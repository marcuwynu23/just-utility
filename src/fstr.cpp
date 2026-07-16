#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     fstr - Find string in source files" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     fstr [--help | -h] <extension> <string>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Searches for a string in all source files with the given" << endl;
    cout << "     extension in the current directory. Shows both exact" << endl;
    cout << "     matches and partial matches using Windows findstr." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <extension>  File extension to search (e.g., cpp, h, txt)" << endl;
    cout << "     <string>     The string to search for" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     findstr (Windows built-in utility)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     fstr cpp int            Search for 'int' in all .cpp files" << endl;
    cout << "     fstr txt todo           Search for 'todo' in all .txt files" << endl;
    cout << "     fstr --help             Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string arg1,arg2,cmd1,cmd2;

	if(argv[1] != NULL && argv[2] != NULL ){
		arg1 = argv[1];
		arg2 = argv[2];
		cmd1 = "findstr /O /N /X "+ arg2 + " *."+arg1;
		cmd2 = "findstr /O /N "+ arg2 + " *."+arg1;
		peculiar::print("Exact Result:");
		peculiar::runExe(cmd1);
		peculiar::print("Other Result:");
		peculiar::runExe(cmd2);

	}else{
		showHelp();
	}
	return 0;
} 
