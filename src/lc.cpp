#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     lc - Locate a file or directory" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     lc [--help | -h] <file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Searches for a file or directory by name starting from" << endl;
    cout << "     the current directory and recursively through subdirectories." << endl;
    cout << "     Uses the Windows 'dir /B /S' and 'findstr' commands." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file>  Name or pattern of the file to locate" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     lc main.cpp          Find main.cpp in current directory tree" << endl;
    cout << "     lc *.txt             Find all .txt files recursively" << endl;
    cout << "     lc --help            Show this help" << endl;
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
		cmd = "dir /B /S "+arg1+" | findstr "+arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 

