# Just Utility — User Guide

A comprehensive reference for every command in the Just Utility collection.

- [Installation](#installation)
- [Quick Start](#quick-start)
- [Command Reference](#command-reference)
  - [File Operations](#file-operations)
  - [Code Interpretation](#code-interpretation)
  - [Project Scaffolding](#project-scaffolding)
  - [System Utilities](#system-utilities)
  - [Launchers](#launchers)
- [Configuration](#configuration)
- [Workflows](#workflows)
- [Troubleshooting](#troubleshooting)
- [FAQ](#faq)

---

## Installation

### Prerequisites

Most commands require **no external dependencies**. The code interpreters do require their respective compilers/runtimes:

| Command | Dependency | Purpose |
|---|---|---|
| `cci` | clang | C compilation |
| `cppi` | clang++ | C++ compilation |
| `csi` | csc | C# compilation |
| `jvi` | javac / java | Java compilation and execution |
| `jpb` | javac / jar | Java project building |
| `pyr` | python | Python script execution |
| `jr` | java | JAR execution |
| `sqlt3` | sqlite3 | SQLite database queries |
| `arts` | php | Laravel Artisan commands |
| `chrome-dev` | Chrome | Browser with DevTools |
| `droid` | ADB | Android device connectivity |

### Download

1. Go to the [Releases page](https://github.com/marcuwynu23/just-utility/releases)
2. Download `just-utility.zip`
3. Extract to your preferred location

### Build from Source

```bash
git clone https://github.com/marcuwynu23/just-utility.git
cd just-utility
make all
```

### Add to PATH

```cmd
setx PATH "%PATH%;C:\path\to\just-utility\dist"
```

Restart your terminal for the changes to take effect.

### Verify Installation

```cmd
justutil
```

You should see the list of available commands.

---

## Quick Start

```cmd
justutil                # List all commands
ls                      # List files in current directory
cf hello.txt            # Create a file
cat hello.txt           # Display file contents
mv hello.txt ..\        # Move file to parent directory
rm hello.txt            # Delete a file
cci hello               # Compile and run hello.c
jvi Hello               # Compile and run Hello.java
xr                      # Open File Explorer
dt                      # Show date and time
<command> --help        # Show detailed help for any command
```

---

## Command Reference

Every command supports `--help` and `-h` for detailed man-page style documentation.

### File Operations

#### `cat`

Display the contents of a file.

```cmd
cat [--help | -h] [file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
cat README.md
cat src\main.cpp
```

**Dependencies:** None (uses Windows `type`).

---

#### `cf`

Create an empty file. If the file already exists, its contents are cleared.

```cmd
cf [--help | -h] [file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
cf main.cpp
cf src\util.h
```

**Dependencies:** None (uses Windows `echo.`).

---

#### `fp`

Display file properties and layout information.

```cmd
fp [--help | -h] [file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
fp main.cpp
fp C:\file.txt
```

**Dependencies:** `fsutil` (Windows built-in).

---

#### `fstr`

Search for a string in all source files with a given extension in the current directory.

```cmd
fstr [--help | -h] [extension] [string]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Arguments:**

| Argument | Description |
|---|---|
| `extension` | File extension to search (e.g., `cpp`, `h`, `txt`) |
| `string` | The string to search for |

**Examples:**

```cmd
fstr cpp int
fstr txt todo
```

**Dependencies:** `findstr` (Windows built-in).

---

#### `lc`

Locate a file or directory by name, searching recursively from the current directory.

```cmd
lc [--help | -h] [file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
lc main.cpp
lc *.txt
```

**Dependencies:** None (uses Windows `dir` and `findstr`).

---

#### `ls`

List all files and directories in the current directory, sorted by date (newest first).

```cmd
ls [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
ls
```

**Dependencies:** None (uses Windows `dir /B /O-D`).

---

#### `mv`

Move or rename a file.

```cmd
mv [--help | -h] [source] [destination]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
mv file.txt ..\
mv old.txt new.txt
```

**Dependencies:** None (uses Windows `move`).

---

#### `rm`

Delete a file.

```cmd
rm [--help | -h] [file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
rm temp.txt
rm ..\old.log
```

**Dependencies:** None (uses Windows `del`).

---

### Code Interpretation

#### `cci`

Compile and run a C source file in a single step. The source is compiled with `clang`, executed, and the binary is cleaned up automatically. Shows compile and execution times.

```cmd
cci [--help | -h] [sourcefile]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Arguments:**

| Argument | Description |
|---|---|
| `sourcefile` | Name of the C source file (without `.c` extension) |

**Examples:**

```cmd
cci hello
```

**Output:**

```
hello world

compile time: 0.452s
running time: 0.021s
```

**Dependencies:** `clang` (LLVM).

---

#### `cppi`

Compile and run a C++ source file in a single step. Compiled with `clang++`, executed, then cleaned up.

```cmd
cppi [--help | -h] [sourcefile]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Arguments:**

| Argument | Description |
|---|---|
| `sourcefile` | Name of the C++ source file (without `.cpp` extension) |

**Examples:**

```cmd
cppi hello
```

**Dependencies:** `clang++` (LLVM).

---

#### `csi`

Compile and run a C# source file in a single step using the C# compiler (`csc`).

```cmd
csi [--help | -h] [sourcefile]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Arguments:**

| Argument | Description |
|---|---|
| `sourcefile` | Name of the C# source file (without `.cs` extension) |

**Examples:**

```cmd
csi program
```

**Dependencies:** `csc` (.NET Framework SDK / Roslyn).

---

#### `jvi`

Compile and run a Java source file in a single step. Compiled with `javac`, executed with `java`, then `.class` files are cleaned up.

```cmd
jvi [--help | -h] [sourcefile]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Arguments:**

| Argument | Description |
|---|---|
| `sourcefile` | Name of the Java source file (without `.java` extension) |

**Examples:**

```cmd
jvi Hello
```

**Dependencies:** `javac`, `java` (JDK).

---

### Project Scaffolding

#### `arts`

Quick access to common Laravel Artisan commands.

```cmd
arts [--help | -h] [command]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Available commands:**

| Subcommand | Description |
|---|---|
| `serve` | Start dev server at http://localhost:8000 |
| `controller` | Create a new controller class |
| `migration` | Create a new database migration |
| `model` | Create a new Eloquent model class |
| `migrate` | Run outstanding migrations |
| `migrate_refresh` | Roll back and re-run all migrations |
| `config_cache` | Cache configuration for faster performance |

**Examples:**

```cmd
arts serve
arts migration
```

**Dependencies:** `php` (PHP CLI), Laravel project in current directory.

---

#### `ctp`

Create a project directory structure for the specified language or project type.

```cmd
ctp [--help | -h] [language] [project-name]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Available languages:**

| Language | Generated Structure |
|---|---|
| `java` | `src/`, `docs/screenshots/`, `docs/docs.html`, LICENSE, README.md |
| `python` | `app/`, `main.py`, `setup.py`, `docs/`, LICENSE, README.md |
| `web` | `static/js/`, `static/css/`, `templates/`, `index.html`, `screenshots/` |
| `js-web-app` | Full MVC structure: `public/`, `view/`, `router/`, `controller/`, `database/`, `constant/`, `app.js` |
| `php-web-app` | Full MVC structure (PHP variant) |
| `c` / `cpp` / `c++` | `src/include/`, `makefile`, `docs/` |
| (any other) | `src/`, `docs/`, LICENSE, README.md |

**Examples:**

```cmd
ctp java myapp
ctp python myapp
ctp js-web-app myapp
```

**Dependencies:** `cf` (this project), Windows `md` command.

---

#### `jpb`

A complete Java project build tool. Initialize, manage packages, compile, package JARs, and generate documentation.

```cmd
jpb [--help | -h] [option] [args...]
```

| Flag/option | Description |
|---|---|
| `--help`, `-h` | Show help and exit |
| `--init` | Initialize a new Java project structure |
| `--md <package>` | Create a new package (directory) |
| `--cf <pkg> <file>` | Create a source file inside a package |
| `--aim <attr> <val>` | Add an attribute to `JMANIFEST.info` |
| `--adeps <deps>` | Add dependencies to the project |
| `--compile` | Compile and package into a JAR |
| `--compile-deps` | Compile and package with dependencies |
| `--docs` | Generate Javadoc documentation |
| `--run` | Run the project JAR |
| `--test` | Run the test source file |

**Workflow example:**

```cmd
jpb --init
jpb --md com.example
jpb --cf com.example Main.java
jpb --compile
jpb --run
```

**Dependencies:** `javac`, `jar` (JDK), `cf` (this project).

---

#### `sqlt3`

Execute SQL commands from a source file against a SQLite3 database.

```cmd
sqlt3 [--help | -h] [output-file] [source-file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
sqlt3 test.db init.sql
```

**Dependencies:** `sqlite3` (SQLite command-line tool).

---

### System Utilities

#### `chrome-dev`

Open Google Chrome with Developer Tools automatically opened for the given URL.

```cmd
chrome-dev [--help | -h] [url]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
chrome-dev http://localhost:8000
chrome-dev https://example.com
```

**Dependencies:** Google Chrome.

---

#### `ct`

Open a new Windows Command Prompt window — effectively cloning the current terminal.

```cmd
ct [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
ct
```

**Dependencies:** None (uses Windows `start`).

---

#### `dt`

Display the current system date and time.

```cmd
dt [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
dt
```

**Dependencies:** None (uses Windows `date /T` and `time /T`).

---

#### `snip`

Open the Windows Snipping Tool for taking screenshots.

```cmd
snip [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
snip
```

**Dependencies:** Snipping Tool (Windows built-in).

---

#### `wif`

List all saved WiFi profiles, then prompt for a profile name to show details including the Wi-Fi password in clear text.

```cmd
wif [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
wif
```

**Dependencies:** `netsh` (Windows built-in).

---

#### `wr`

Open a URL or HTML file in the system's default web browser.

```cmd
wr [--help | -h] [url | file]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
wr https://google.com
wr index.html
```

**Dependencies:** Default web browser.

---

#### `xr`

Open Windows File Explorer rooted at the current working directory.

```cmd
xr [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
xr
```

**Dependencies:** Windows File Explorer (built-in).

---

### Launchers

#### `droid`

Android device management utility — connect via ADB, push/pull projects, install apps, run apps, and open IDEs.

```cmd
droid [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Dependencies:** ADB (Android Debug Bridge), Android device or emulator.

---

#### `jr`

Run a JAR file located in the `C:/jar/` directory. The `.jar` extension is appended automatically.

```cmd
jr [--help | -h] [file-name] [args]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
jr myapp
jr myapp --verbose
```

**Dependencies:** `java` (JRE).

---

#### `pyr`

Run a Python script located in the `C:/scripts/py/` directory. The `.py` extension is appended automatically.

```cmd
pyr [--help | -h] [file-name] [args]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
pyr myscript
pyr myscript --test
```

**Dependencies:** `python` (Python 3 interpreter).

---

#### `justutil`

Display the list of all available commands in a compact, busybox-style listing.

```cmd
justutil [--help | -h]
```

| Flag | Description |
|---|---|
| `--help`, `-h` | Show help and exit |

**Examples:**

```cmd
justutil
justutil --help
```

**Dependencies:** None.

---

## Configuration

Just Utility does **not** use configuration files. All behavior is controlled through command-line arguments.

### Environment

| Variable | Purpose | Used By |
|---|---|---|
| `PATH` | Must include the `dist/` directory or binary location | All commands |

### Fixed Paths

| Path | Purpose | Used By |
|---|---|---|
| `C:/jar/` | Default JAR directory | `jr` |
| `C:/scripts/py/` | Default Python scripts directory | `pyr` |

---

## Workflows

### Daily Development

```cmd
ls                          # See what's in the directory
cat main.cpp                # Check file contents
cf notes.txt                # Create a quick note
mv notes.txt docs\          # Move it to docs
rm temp.txt                 # Clean up temp files
```

### Code-Test Loop (C)

```cmd
cci hello                   # Code, compile, run, cleanup — repeat
```

### Java Project Lifecycle

```cmd
jpb --init                  # Set up project
jpb --md com.example        # Create package
jpb --cf com.example Main   # Create main class
jpb --compile               # Build JAR
jpb --run                   # Run it
```

### Quick System Info

```cmd
dt                          # What's the date/time?
wif                         # What's my WiFi password?
fp somefile.dll             # What are this file's properties?
lc config.xml               # Where's that config file?
```

---

## Troubleshooting

### "'<command>' is not recognized"

**Cause:** The binary is not in your PATH.

**Fix:** Add the `dist/` directory to your PATH:

```cmd
setx PATH "%PATH%;C:\path\to\just-utility\dist"
```

### "clang is not recognized" (cci / cppi)

**Cause:** The LLVM/clang compiler is not installed or not on PATH.

**Fix:** Install LLVM from https://llvm.org/ and ensure `clang++` is available.

### "javac is not recognized" (jvi / jpb)

**Cause:** The Java Development Kit is not installed.

**Fix:** Install JDK 17+ from https://adoptium.net/ and ensure `javac` is on PATH.

### "csc is not recognized" (csi)

**Cause:** The C# compiler is not installed.

**Fix:** Install the .NET SDK from https://dotnet.microsoft.com/download.

### "sqlite3 is not recognized" (sqlt3)

**Cause:** SQLite3 CLI is not installed.

**Fix:** Download `sqlite3.exe` from https://sqlite.org/download.html and add to PATH.

### "php is not recognized" (arts)

**Cause:** PHP CLI is not installed.

**Fix:** Install PHP from https://windows.php.net/download/ and add to PATH.

---

## FAQ

**Q: Do I need to install anything for the basic commands (ls, mv, rm, etc.)?**

No. Basic file commands use built-in Windows utilities and have zero dependencies.

**Q: How do I get the full documentation for a command?**

Run any command with `--help`: `ls --help`, `jpb --help`, etc. Each page is also available as HTML in the `docs/` directory.

**Q: Can I rename the executables?**

Yes. Each `.exe` is independent. Rename them to whatever fits your workflow.

**Q: Do the interpreters leave temporary files?**

No. `cci`, `cppi`, `csi`, and `jvi` clean up the compiled binary and `.class` files after execution.

**Q: Why is the project built with LLVM/clang instead of MinGW?**

The project switched from MinGW to LLVM/clang for better standards compliance, modern tooling, and MSVC ABI compatibility.

**Q: How do I contribute?**

See [CONTRIBUTING.md](CONTRIBUTING.md) for full details.
