#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     cat - Display the contents of a file" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     cat [--help | -h] <file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Outputs the contents of the specified file to the console." << endl;
    cout << "     Uses the Windows 'type' command internally." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file>  Path to the file to display" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows 'type' command)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     cat README.md         Display README.md contents" << endl;
    cout << "     cat src\\main.cpp     Display source file" << endl;
    cout << "     cat --help            Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	if(argv[1] != NULL){
		string arg1,cmd;
		arg1 = argv[1];
		cmd = "type "+ arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
}

