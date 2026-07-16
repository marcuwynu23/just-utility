<div align="center">

# Just Utility

[![Release](https://img.shields.io/github/v/release/marcuwynu23/just-utility)](https://github.com/marcuwynu23/just-utility/releases)
[![License](https://img.shields.io/github/license/marcuwynu23/just-utility?logo=github)](LICENSE)
[![Stars](https://img.shields.io/github/stars/marcuwynu23/just-utility)](https://github.com/marcuwynu23/just-utility/stargazers)
[![Language](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B)](https://clang.llvm.org/)
[![Build](https://img.shields.io/badge/build-clang++%2018-blue)](https://llvm.org/)

**A multi-call binary for Windows CLI utilities.** File management, code interpretation, project scaffolding, and system tools — all from a single command set.

➡️ **[Read the full user guide →](USER-GUIDE.md)**

</div>

---

## Table of Contents

- [What Is Just Utility?](#what-is-just-utility)
- [Use Cases](#use-cases)
- [Benefits](#benefits)
- [Comparison](#comparison)
- [User Guide](USER-GUIDE.md)
- [Installation](#installation)
- [Quick Start](#quick-start)
- [CLI Reference](#cli-reference)
- [Development](#development)
- [Architecture](#architecture)
- [Contributing](CONTRIBUTING.md)
- [License](#license)

---

## What Is Just Utility?

**Just Utility** is a collection of Windows CLI utilities packaged as individual executables — think of it as a miniature BusyBox for Windows. Each command wraps a common task (file operations, compiling code, network queries, project scaffolding) into a single `cmd` callable binary.

### What It Does

- **Manage files** — list, move, copy, delete, and inspect files with concise commands (`ls`, `mv`, `rm`, `cat`, `fp`, `cf`, `lc`)
- **Interpret code** — compile and run C, C++, C#, and Java source files in one step (`cci`, `cppi`, `csi`, `jvi`)
- **Scaffold projects** — generate skeleton directories for Java, Python, web, JS, PHP, and C/C++ projects (`ctp`)
- **Build Java projects** — initialize, compile, package JARs, generate docs, and run with or without dependencies (`jpb`)
- **Query the system** — display WiFi profiles, file properties, date/time, and locate files (`wif`, `fp`, `dt`, `lc`)
- **Launch tools** — open Chrome with DevTools, Snipping Tool, File Explorer, and browser URLs (`chrome-dev`, `snip`, `xr`, `wr`)
- **Run remote scripts** — execute Python/PHP scripts and JARs from predefined directories (`pyr`, `jr`, `arts`)
- **Assist Android dev** — connect ADB, push/pull projects, install APKs, and run apps on devices (`droid`)

### Why Use It?

| Problem | How Just Utility Solves It |
|---|---|
| Remembering long Windows commands | Single short commands: `ls` instead of `dir /B /O-D` |
| Compiling + running code repeatedly | One-step interpreters: `cci hello` compiles and runs `hello.c` |
| Setting up project structures | `ctp java myapp` creates the full directory skeleton |
| Managing Java projects without an IDE | `jpb` initializes, compiles, packages, and runs from the terminal |
| Finding WiFi passwords | `wif` lists profiles and reveals the key with one command |
| Opening browser + DevTools | `chrome-dev <url>` launches Chrome with devtools auto-opened |

### The Philosophy

1. **Minimal typing, maximum output.** Every command is short and does exactly what you expect.
2. **Built on what's already there.** Where possible, commands wrap built-in Windows utilities (`type`, `dir`, `netsh`, `fsutil`, `findstr`).
3. **Your workflow stays yours.** No lock-in — each binary is independent and can be copied, renamed, or used standalone.

---

## Use Cases

| Scenario | How Just Utility Helps |
|---|---|
| **You're learning C/C++/Java/C#** | `cci`, `cppi`, `jvi`, `csi` compile and run your source in one command, measuring time |
| **You frequently create project templates** | `ctp` generates the full directory tree for any language in seconds |
| **You work with Java from the terminal** | `jpb` handles init, package creation, compilation, and JAR packaging |
| **You need WiFi credentials in a pinch** | `wif` shows all profiles and prints the key in clear text |
| **You manage Android devices** | `droid` connects via ADB, installs APKs, and runs apps automatically |
| **You want a terminal-based file manager** | `ls`, `mv`, `rm`, `cf`, `cat`, `fp` cover all basic file operations |
| **You run the same Python/JAR scripts daily** | `pyr` and `jr` run from fixed directories with a short command |

---

## Benefits

- **Zero configuration.** Download the binaries and they work — no config files, no environment variables (except PATH).
- **Self-contained.** Each `.exe` is standalone. Copy it to any Windows machine and run it.
- **Fast.** Binaries are small (~250 KB each) and launch instantly.
- **Colorful output.** Commands use ANSI colors for readability.
- **Built with LLVM/clang++.** Modern compiler, clean code, easy to build from source.
- **Man-page style `--help`.** Every command has detailed documentation built in.

---

## Comparison

| Aspect | Just Utility | BusyBox for Windows | Manual CMD |
|---|---|---|---|
| **Setup time** | ~10 seconds (add to PATH) | Package manager required | Nothing to install |
| **File operations** | `ls`, `mv`, `rm`, `cat`, `cf`, `fp`, `lc` | Similar | `dir`, `move`, `del`, `type`, `echo. >` |
| **Code compilation** | One-step interpreters | None | Manual `clang` / `javac` + run + cleanup |
| **Project scaffolding** | `ctp` with 7 templates | None | Manual `md` and `echo. >` |
| **Java build tool** | `jpb` with JAR packaging | None | Manual `javac` + `jar` |
| **WiFi info** | `wif` — one command | None | Manual `netsh wlan` |
| **Android integration** | `droid` — ADB automation | None | Manual ADB commands |
| **Dependencies** | LLVM/clang++ (only for interpreters) | None | None |
| **License** | Apache 2.0 | GPL | N/A |

---

## Installation

### Option 1: Download from Releases

1. Go to the [Releases page](https://github.com/marcuwynu23/just-utility/releases)
2. Download the latest `just-utility.zip`
3. Extract to a folder (e.g., `C:\tools\just-utility`)
4. Add the folder to your `PATH`:
   ```cmd
   setx PATH "%PATH%;C:\tools\just-utility\dist"
   ```

### Option 2: Build from Source

```bash
# Prerequisites: LLVM/clang++ and GNU Make
git clone https://github.com/marcuwynu23/just-utility.git
cd just-utility
make all
```

Binaries will be in `dist/`.

### Verify

```cmd
justutil --help
```

---

## Quick Start

```bash
# List available commands
justutil

# List files in current directory
ls

# Create a file
cf hello.txt

# Display its contents
cat hello.txt

# Compile and run a C program
cci hello

# Compile and run a Java program
jvi Hello

# Open File Explorer
xr

# Get WiFi info
wif

# Show help for any command
ls --help
```

---

## CLI Reference

All commands accept `--help` or `-h` for detailed usage. Below is a quick overview.

### File Operations

| Command | Description |
|---|---|
| [`cat`](docs/cat.html) | Display file contents |
| [`cf`](docs/cf.html) | Create an empty file |
| [`fp`](docs/fp.html) | Display file properties |
| [`fstr`](docs/fstr.html) | Find string in source files |
| [`lc`](docs/lc.html) | Locate a file or directory |
| [`ls`](docs/ls.html) | List directory contents |
| [`mv`](docs/mv.html) | Move or rename a file |
| [`rm`](docs/rm.html) | Remove a file |

### Code Interpretation

| Command | Description | Requires |
|---|---|---|
| [`cci`](docs/cci.html) | C interpreter (compile + run) | clang |
| [`cppi`](docs/cppi.html) | C++ interpreter (compile + run) | clang++ |
| [`csi`](docs/csi.html) | C# interpreter (compile + run) | csc |
| [`jvi`](docs/jvi.html) | Java interpreter (compile + run) | javac/java |

### Project Scaffolding

| Command | Description | Requires |
|---|---|---|
| [`arts`](docs/arts.html) | Laravel Artisan command helper | php |
| [`ctp`](docs/ctp.html) | Create project templates | cf |
| [`jpb`](docs/jpb.html) | Java project builder | javac/jar |
| [`sqlt3`](docs/sqlt3.html) | Run SQLite3 source files | sqlite3 |

### System Utilities

| Command | Description |
|---|---|
| [`chrome-dev`](docs/chrome-dev.html) | Open Chrome with DevTools |
| [`ct`](docs/ct.html) | Clone current terminal instance |
| [`dt`](docs/dt.html) | Display date and time |
| [`snip`](docs/snip.html) | Open Windows Snipping Tool |
| [`wif`](docs/wif.html) | Show WiFi profile information |
| [`wr`](docs/wr.html) | Open URL/file in browser |
| [`xr`](docs/xr.html) | Open Explorer in current directory |

### Launchers

| Command | Description | Requires |
|---|---|---|
| [`droid`](docs/droid.html) | Android device helper (droiddroid) | ADB |
| [`jr`](docs/jr.html) | Run JAR files from `C:/jar/` | java |
| [`pyr`](docs/pyr.html) | Run Python scripts from `C:/scripts/py/` | python |
| [`justutil`](docs/justutil.html) | Show this command list | — |

See the **[full user guide](USER-GUIDE.md)** for detailed documentation of every command, flag, and example.

---

## Development

### Prerequisites

| Tool | Version | Purpose |
|---|---|---|
| LLVM/clang++ | 18+ | C++ compiler |
| GNU Make | 3.81+ | Build system |
| Git | Any | Version control |

### Build

```bash
make all        # Build all 26 binaries
make clean      # Remove built binaries
```

### Test

```powershell
tests\run.ps1   # Run the test suite
```

### Project Structure

```
just-utility/
├── dist/              # Built binaries
├── docs/              # HTML documentation
│   └── index.html     # Command listing (categorized)
├── src/               # Source files
│   ├── <cmd>.cpp      # One file per command
│   ├── runner.cpp     # Shared runtime utility
│   ├── include/
│   │   └── runner.h   # Shared header
│   └── droidroid/     # Android device helper
├── tests/             # PowerShell test suite
├── Makefile           # Build system
└── README.md
```

### Coding Standards

- C++17
- One `.cpp` file per command
- All commands include `runner.h`
- Use `peculiar::runExe()` for system calls
- `showHelp()` static function for `--help` output
- Man-page style help with sections: NAME, SYNOPSIS, DESCRIPTION, OPTIONS, ARGUMENTS, DEPENDENCIES, EXAMPLES

---

## Architecture

- **Multi-call binary pattern.** Each command is a standalone `.exe` sharing a common runtime (`runner.cpp` / `runner.h`).
- **System call abstraction.** `peculiar::runExe()` wraps `system()` with thread-safe logging.
- **Windows-native.** Commands use built-in Windows utilities (`type`, `dir`, `netsh`, `fsutil`, `findstr`, `explorer`) and standard system compilers (`clang`, `javac`, `csc`).
- **Self-documenting.** Every command implements `--help` with man-page style output and has a corresponding HTML documentation page.
- **LLVM toolchain.** Built with `clang++` targeting `x86_64-pc-windows-msvc`.

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for full details on how to contribute, including the commit convention, PR process, and development workflow.

---

## License

Licensed under the [Apache License, Version 2.0](LICENSE).

Built with LLVM/clang++ on Windows.
