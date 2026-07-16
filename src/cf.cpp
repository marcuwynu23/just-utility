#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     cf - Create an empty file" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     cf [--help | -h] <file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Creates an empty file at the specified path." << endl;
    cout << "     If the file already exists, its contents are cleared." << endl;
    cout << "     Uses the Windows 'echo.' command internally." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file>  Path of the file to create" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     cf main.cpp          Create main.cpp" << endl;
    cout << "     cf src\\util.h       Create util.h in src directory" << endl;
    cout << "     cf --help            Show this help" << endl;
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
		cmd = "echo. > "+ arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 

