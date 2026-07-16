/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     ct - Clone the current terminal instance" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     ct [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Opens a new Windows Command Prompt window. Effectively" << endl;
    cout << "     clones the current terminal instance." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows 'start' command)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     ct                 Open a new terminal window" << endl;
    cout << "     ct --help          Show this help" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    string a = argv[1];
    if (a == "--help" || a == "-h") { showHelp(); return 0; }
  }
  if (argv[1] != NULL) {
    showHelp();
  } else {
    string cmd;
    cmd = "start cmd";
    peculiar::runExe(cmd);
  }
  return 0;
}
