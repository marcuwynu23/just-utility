param(
    [string[]]$Command = @()
)

$DistDir = Join-Path (Split-Path -Parent $PSScriptRoot) "dist"
$Passed = 0
$Failed = 0
$Results = @()

function Test-HelpOutput {
    param([string]$Cmd, [string[]]$Expected, [switch]$SkipHelpCheck)

    $exe = Join-Path $DistDir "$Cmd.exe"
    if (-not (Test-Path $exe)) {
        Write-Host "  FAIL: $Cmd.exe not found" -ForegroundColor Red
        return $false
    }

    # Test --help
    $output = & $exe --help 2>&1 | Out-String

    if ($SkipHelpCheck) {
        $helpOk = $true
    } else {
        $helpOk = $output -match "NAME" -and $output -match "SYNOPSIS"
        $helpOk = $helpOk -and $output -match "DESCRIPTION"
    }

    if (-not $helpOk) {
        Write-Host "  FAIL: $Cmd --help missing expected sections" -ForegroundColor Red
        return $false
    }

    foreach ($exp in $Expected) {
        if ($output -notmatch [regex]::Escape($exp)) {
            Write-Host "  FAIL: $Cmd --help missing '$exp'" -ForegroundColor Red
            return $false
        }
    }

    # Test -h also works
    $outputH = & $exe -h 2>&1 | Out-String

    if (-not $SkipHelpCheck) {
        if ($outputH -notmatch "NAME") {
            Write-Host "  FAIL: $Cmd -h did not show help" -ForegroundColor Red
            return $false
        }
    }

    Write-Host "  PASS" -ForegroundColor Green
    return $true
}

function Test-NoArgsShowsHelp {
    param([string]$Cmd)

    $exe = Join-Path $DistDir "$Cmd.exe"
    if (-not (Test-Path $exe)) { return $false }

    $output = & $exe 2>&1 | Out-String
    if ($output -match "NAME" -or $output -match "SYNOPSIS") {
        return $true
    }
    return $false
}

$Commands = @(
    @{Name="arts";        Expected=@("artisan", "serve", "controller")}
    @{Name="cat";         Expected=@("<file>", "type")}
    @{Name="cci";         Expected=@("C source", "clang", "<sourcefile>")}
    @{Name="cf";          Expected=@("empty file", "<file>")}
    @{Name="chrome-dev";  Expected=@("Chrome", "DevTools", "<url>")}
    @{Name="cppi";        Expected=@("C++", "clang++", "<sourcefile>")}
    @{Name="csi";         Expected=@("C#", "csc", "<sourcefile>")}
    @{Name="ct";          Expected=@("Clone", "terminal")}
    @{Name="ctp";         Expected=@("project", "templates", "<language>")}
    @{Name="dt";          Expected=@("date", "time")}
    @{Name="fp";          Expected=@("file properties", "fsutil")}
    @{Name="fstr";        Expected=@("find string", "extension")}
    @{Name="jpb";         Expected=@("Java Project Builder", "--compile", "--init")}
    @{Name="jr";          Expected=@("JAR", "C:/jar/")}
    @{Name="justutil";    Expected=@("multi-call binary", "Currently defined"); SkipHelpCheck=$true}
    @{Name="jvi";         Expected=@("Java", "javac", "<sourcefile>")}
    @{Name="lc";          Expected=@("Locate", "<file>")}
    @{Name="ls";          Expected=@("directory", "dir")}
    @{Name="mv";          Expected=@("Move", "rename", "<source>")}
    @{Name="pyr";         Expected=@("Python", "C:/scripts/py/")}
    @{Name="rm";          Expected=@("Remove", "delete", "<file>")}
    @{Name="snip";        Expected=@("Snipping Tool")}
    @{Name="sqlt3";       Expected=@("SQLite3", "<output-file>")}
    @{Name="wif";         Expected=@("WiFi", "profile")}
    @{Name="wr";          Expected=@("URL", "browser")}
    @{Name="xr";          Expected=@("File Explorer", "current directory")}
)

if ($Command.Count -gt 0) {
    $Commands = $Commands | Where-Object { $_.Name -in $Command }
}

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Just Utility - Test Suite" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

foreach ($c in $Commands) {
    Write-Host "Testing $($c.Name)..." -ForegroundColor Yellow
    $skip = if ($c.SkipHelpCheck) { $true } else { $false }
    $ok = Test-HelpOutput -Cmd $c.Name -Expected $c.Expected -SkipHelpCheck:$skip

    if ($c.Name -in @("cat","cf","cci","cppi","csi","ctp","fp","fstr","jpb","jr","jvi","lc","mv","pyr","rm","sqlt3","wr")) {
        $noargs = Test-NoArgsShowsHelp -Cmd $c.Name
        if (-not $noargs) {
            Write-Host "  WARN: $($c.Name) with no args may not show help" -ForegroundColor DarkYellow
        }
    }

    if ($ok) { $Passed++ } else { $Failed++ }
    $Results += [PSCustomObject]@{ Command = $c.Name; Passed = $ok }
    ""
}

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Results: $Passed passed, $Failed failed" -ForegroundColor $(if ($Failed -eq 0) {"Green"} else {"Red"})
Write-Host "========================================" -ForegroundColor Cyan

exit $Failed
