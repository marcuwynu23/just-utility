#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     xr - Open File Explorer in the current directory" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     xr [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Opens a Windows File Explorer window rooted at the" << endl;
    cout << "     current working directory." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     Windows File Explorer (built-in)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     xr                  Open Explorer in current directory" << endl;
    cout << "     xr --help           Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	peculiar::runExe("explorer .");
	peculiar::print("open file explorer in current directory");
	return 0;
} 
