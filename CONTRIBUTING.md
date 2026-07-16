# Contributing to Just Utility

Thank you for your interest in contributing! This document covers everything you need to get started.

- [Code of Conduct](#code-of-conduct)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Makefile Reference](#makefile-reference)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Adding a New Command](#adding-a-new-command)
- [Testing](#testing)
- [Commit Conventions](#commit-conventions)
- [Pull Request Process](#pull-request-process)
- [Release Process](#release-process)
- [Questions](#questions)

---

## Code of Conduct

This project is governed by the [Contributor Covenant](https://www.contributor-covenant.org/). By participating, you agree to uphold this code. Report unacceptable behavior to the project maintainer.

---

## Prerequisites

| Tool | Version | Purpose |
|---|---|---|
| LLVM/clang++ | 18+ | C++17 compiler |
| GNU Make | 3.81+ | Build system |
| Git | Any | Version control |
| PowerShell | 7+ | Test runner |

### Optional

| Tool | Purpose |
|---|---|
| Python 3 | Testing `pyr` changes |
| Java JDK 17+ | Testing `jvi` / `jpb` changes |
| SQLite3 CLI | Testing `sqlt3` changes |
| PHP CLI | Testing `arts` changes |

---

## Project Structure

```
just-utility/
├── dist/               # Built binaries (gitignored)
├── docs/               # HTML documentation
│   ├── index.html      # Command listing (categorized)
│   ├── <cmd>.html      # Individual man pages
│   └── images/         # Screenshots
├── src/                # Source files
│   ├── <cmd>.cpp       # One file per command
│   ├── runner.cpp      # Shared runtime: system calls, path resolution
│   ├── include/
│   │   └── runner.h    # Shared header with utility declarations
│   └── droidroid/      # Separate Android device helper
│       ├── droiddroid.cpp
│       └── makefile
├── tests/              # Test suite
│   └── run.ps1         # PowerShell test runner
├── Makefile            # Build system (clang++, GNU Make)
├── README.md           # Project overview
├── USER-GUIDE.md       # Full command reference
└── CONTRIBUTING.md     # This file
```

---

## Makefile Reference

| Target | Description |
|---|---|
| `make all` | Build all 26 binaries into `dist/` |
| `make clean` | Remove all built binaries from `dist/` |
| `make dist/<cmd>.exe` | Build a single command (e.g., `make dist/ls.exe`) |

### Make Variables

| Variable | Default | Description |
|---|---|---|
| `CXX` | `clang++` | C++ compiler |
| `CXXFLAGS` | `-std=c++17 -I src/include` | Compiler flags |
| `LDFLAGS` | `-lshlwapi` | Linker flags |
| `SRCDIR` | `src` | Source directory |
| `DISTDIR` | `dist` | Output directory |

---

## Development Workflow

1. **Fork** the repository on GitHub.
2. **Clone** your fork:
   ```bash
   git clone https://github.com/your-username/just-utility.git
   ```
3. **Create a branch** for your changes:
   ```bash
   git checkout -b feat/my-feature
   ```
4. **Make your changes.** Follow the coding standards (see below).
5. **Build** to verify compilation:
   ```bash
   make all
   ```
6. **Run tests** to verify nothing is broken:
   ```powershell
   tests\run.ps1
   ```
7. **Commit** using conventional commits format:
   ```bash
   git commit -m "feat(ls): add --sort flag for directory listing"
   ```
8. **Push** to your fork:
   ```bash
   git push -u origin feat/my-feature
   ```
9. **Open a pull request** against the `main` branch.

---

## Coding Standards

### C++ Style

- **Language:** C++17
- **Naming:** `camelCase` for variables and functions, `PascalCase` for classes (minimal class usage)
- **Formatting:** 4-space indentation, no tabs
- **Headers:** Always include `runner.h` first, then standard library headers
- **System calls:** Use `peculiar::runExe()` — never call `system()` directly
- **Output:** Use `peculiar::print()` or `cout` directly
- **No external dependencies:** The project only links against `shlwapi.lib` (Windows SDK)

### Command Structure

Every command follows this pattern:

```cpp
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     <cmd> - <one-line description>" << endl;
    // ... SYNOPSIS, DESCRIPTION, OPTIONS, ARGUMENTS, DEPENDENCIES, EXAMPLES
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        string a = argv[1];
        if (a == "--help" || a == "-h") { showHelp(); return 0; }
    }
    // ... command logic
    return 0;
}
```

### Help Format

Every `--help` output must include these sections in order:

1. **NAME** — command name and one-line description
2. **SYNOPSIS** — usage syntax
3. **DESCRIPTION** — detailed behavior explanation
4. **OPTIONS** — flags and their descriptions (table)
5. **ARGUMENTS** — positional arguments (if any)
6. **DEPENDENCIES** — required external tools
7. **EXAMPLES** — usage examples

### HTML Documentation

Every command must have a corresponding `.html` file in `docs/`. The HTML follows the same section structure and links back to `docs/index.html`.

---

## Adding a New Command

1. **Create** `src/<cmd>.cpp` following the template above.
2. **Add** the binary name to the `BINS` list in the root `Makefile`.
3. **Create** `docs/<cmd>.html` following the HTML template in `docs/index.html`.
4. **Add** the command to `src/justutil.cpp`'s `CMDS` array.
5. **Add** a test entry to `tests/run.ps1`.
6. **Build** and verify: `make all && tests\run.ps1`.
7. **Commit** with message: `feat(<cmd>): add --help flag and documentation page`.

---

## Testing

### Running Tests

```powershell
tests\run.ps1                     # Test all commands
tests\run.ps1 -Command ls,cat     # Test specific commands
```

### Test Structure

Tests verify that every command:
- Produces valid `--help` output containing required sections (NAME, SYNOPSIS, DESCRIPTION)
- Responds correctly to `-h`
- Runs without crashing when given valid arguments

### Adding Tests for a New Command

Open `tests/run.ps1` and add an entry to the `$Commands` array:

```powershell
@{Name="mycmd"; Expected=@("keyword1", "keyword2")}
```

The test will automatically verify that `--help` output contains those keywords.

---

## Commit Conventions

This project uses [Conventional Commits](https://www.conventionalcommits.org/) for all commit messages.

### Format

```
<type>(<scope>): <description>
```

### Types

| Type | Usage |
|---|---|
| `feat` | A new feature or command |
| `fix` | A bug fix |
| `docs` | Documentation changes (README, HTML, user guide) |
| `test` | Test suite changes |
| `refactor` | Code restructuring without feature changes |
| `chore` | Build, tooling, license, or config changes |
| `style` | Formatting, whitespace (no logic change) |

### Scope

The scope should be the command name (e.g., `ls`, `cci`, `jpb`) or the affected area (`makefile`, `runner`, `docs`).

### Examples

```
feat(ls): add --help flag and documentation page
fix(cppi): handle file paths with spaces
docs: add USER-GUIDE.md with full command reference
test: add test suite for all commands
refactor(justutil): rewrite with busybox-style output
chore: replace compile.cmd with Makefile
```

### Breaking Changes

Add `BREAKING CHANGE:` in the body for breaking changes:

```
feat(runner): change runExe signature

BREAKING CHANGE: runExe now requires a mutex parameter.
```

---

## Pull Request Process

### Before Submitting

- [ ] Code compiles: `make all` succeeds
- [ ] Tests pass: `tests\run.ps1` reports 0 failures
- [ ] No new warnings from clang++ (except the pre-existing `-Wreturn-type-c-linkage` warning in `runner.h`)
- [ ] New commands include `--help` support
- [ ] New commands have an HTML doc page in `docs/`
- [ ] New commands are listed in `justutil` and `README.md`
- [ ] Commit messages follow conventional commits format

### Review Criteria

- **Correctness** — Does the code do what it claims?
- **Simplicity** — Is there a simpler way to achieve the same result?
- **Consistency** — Does it follow existing patterns in the codebase?
- **Documentation** — Are `--help` and the HTML doc page complete?

### Merge

Maintainers will squash-merge PRs into `main`. The merge commit message should use conventional commits format.

---

## Release Process

1. Ensure `main` is stable (all tests pass).
2. Update version references in `docs/index.html`.
3. Tag the release:
   ```bash
   git tag v1.0.0
   git push origin v1.0.0
   ```
4. Build binaries:
   ```bash
   make clean && make all
   ```
5. Create a GitHub Release from the tag, attaching the `dist/` binaries as a ZIP archive:
   ```bash
   git archive --format=zip --prefix=v1.0.0/ HEAD > just-utility-v1.0.0.zip
   ```

---

## Questions

- **Issues:** [github.com/marcuwynu23/just-utility/issues](https://github.com/marcuwynu23/just-utility/issues)
- **Discussions:** [github.com/marcuwynu23/just-utility/discussions](https://github.com/marcuwynu23/just-utility/discussions)
- **Author:** [@marcuwynu23](https://github.com/marcuwynu23)

For bug reports, please include:
- Command and arguments used
- Expected output vs actual output
- Windows version and compiler version (if building from source)
