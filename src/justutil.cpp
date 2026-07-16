#include "runner.h"

static const string B = "\u001B[1m";    // bold
static const string G = "\u001B[0;92m"; // green
static const string C = "\u001B[0;96m"; // cyan
static const string Y = "\u001B[0;93m"; // yellow
static const string D = "\u001B[0;90m"; // dim
static const string N = "\u001B[0m";    // reset

struct Cmd { const char *name; const char *desc; };

static const Cmd CMDS[] = {
    {"arts",       "Laravel Artisan command helper"},
    {"cat",        "Display file contents"},
    {"cci",        "C interpreter (requires clang)"},
    {"cf",         "Create an empty file"},
    {"chrome-dev", "Open Chrome with DevTools"},
    {"cppi",       "C++ interpreter (requires clang++)"},
    {"csi",        "C# interpreter (requires csc)"},
    {"ct",         "Clone current terminal instance"},
    {"ctp",        "Create project templates"},
    {"droid",      "Android device helper"},
    {"dt",         "Display date and time"},
    {"fp",         "Display file properties"},
    {"fstr",       "Find string in source files"},
    {"jpb",        "Java project builder"},
    {"jr",         "Run JAR files from C:/jar/"},
    {"justutil",   "Show this command list"},
    {"jvi",        "Java interpreter (requires JDK)"},
    {"lc",         "Locate a file or directory"},
    {"ls",         "List directory contents"},
    {"mv",         "Move or rename a file"},
    {"pyr",        "Run Python scripts from C:/scripts/py/"},
    {"rm",         "Remove a file"},
    {"snip",       "Open Windows Snipping Tool"},
    {"sqlt3",      "Run SQLite3 source files"},
    {"wif",        "Show WiFi profile information"},
    {"wr",         "Open URL/file in browser"},
    {"xr",         "Open Explorer in current directory"},
};

static void printCmd(const Cmd &c, bool hilite) {
    cout << (hilite ? G : D) << "  " << c.name;
    for (int i = 12 - strlen(c.name); i > 0; i--) cout << ' ';
    cout << N << c.desc << endl;
}

static void showHelp() {
    cout << C << "justutil" << N << " - multi-call binary for Windows CLI utilities" << endl;
    cout << endl;
    cout << "Usage: " << Y << "<command> [--help] [arguments...]" << N << endl;
    cout << endl;
    cout << B << "Currently defined functions:" << N << endl;
    cout << endl;
    for (auto &c : CMDS)
        printCmd(c, true);
    cout << endl;
    cout << "Run \"" << Y << "<command> --help" << N << "\" for detailed usage." << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        string a = argv[1];
        if (a == "--help" || a == "-h") { showHelp(); return 0; }
    }

    cout << C << "Just Utility" << N << " - multi-call binary" << endl;
    cout << "Usage: " << Y << "<command> [--help] [arguments...]" << N << endl;
    cout << endl;
    cout << B << "Currently defined functions:" << N << endl;
    cout << endl;

    for (size_t i = 0; i < sizeof(CMDS)/sizeof(CMDS[0]); i++) {
        bool hilite = (i % 2 == 0);
        printCmd(CMDS[i], hilite);
    }

    cout << endl;
    cout << "Run \"" << Y << "<command> --help" << N << "\" for detailed usage." << endl;
    return 0;
} 
