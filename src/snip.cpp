#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     snip - Open Windows Snipping Tool" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     snip [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Opens the Windows Snipping Tool for taking screenshots." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     Snipping Tool (built-in Windows utility)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     snip                Open Snipping Tool" << endl;
    cout << "     snip --help         Show this help" << endl;
}

int main(int argc, char const *argv[]) {
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	peculiar::runExe("snippingtool");
	return 0;
}