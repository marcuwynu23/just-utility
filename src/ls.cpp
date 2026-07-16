#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     ls - List directory contents" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     ls [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Lists all files and directories in the current directory." << endl;
    cout << "     Entries are sorted by date (newest first)." << endl;
    cout << "     Uses the Windows 'dir /B /O-D' command internally." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     ls                  List current directory" << endl;
    cout << "     ls --help           Show this help" << endl;
}

int main(int argc, char const *argv[]) {
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	peculiar::runExe("dir /B /O-D");
	return 0;
}