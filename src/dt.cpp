#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     dt - Display current date and time" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     dt [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Displays the current system date and time." << endl;
    cout << "     Uses the Windows 'date /T' and 'time /T' commands." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     dt                 Show current date and time" << endl;
    cout << "     dt --help          Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string cmd;
	cmd = "date /T && time /T";
	peculiar::runExe(cmd);
	return 0;
}

