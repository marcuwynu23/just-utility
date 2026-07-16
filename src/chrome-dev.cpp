// chrome --auto-open-devtools-for-tabs
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     chrome-dev - Open Chrome with DevTools enabled" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     chrome-dev [--help | -h] <url>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Opens Google Chrome with the Developer Tools panel" << endl;
    cout << "     automatically opened for the specified URL." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <url>  The URL or HTML file to open" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     Google Chrome (must be installed and on PATH)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     chrome-dev http://localhost:8000    Open localhost with DevTools" << endl;
    cout << "     chrome-dev https://example.com      Open URL with DevTools" << endl;
    cout << "     chrome-dev --help                   Show this help" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    string a = argv[1];
    if (a == "--help" || a == "-h") { showHelp(); return 0; }
  }
  if (argv[1] != NULL) {
    string v, cmd;
    v = argv[1];
    cmd = "chrome --auto-open-devtools-for-tabs " + v;
    peculiar::runExe(cmd);
  } else {
    showHelp();
  }
  return 0;
}
