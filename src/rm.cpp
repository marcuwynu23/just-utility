#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     rm - Remove (delete) a file" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     rm [--help | -h] <file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Deletes the specified file from the filesystem." << endl;
    cout << "     Uses the Windows 'del' command internally." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file>  Path to the file to delete" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     rm temp.txt            Delete temp.txt" << endl;
    cout << "     rm ..\\old.log          Delete file in parent directory" << endl;
    cout << "     rm --help              Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string arg1,cmd;

	if(argv[1] != NULL){
		arg1 = argv[1];
		cmd = "del "+ arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 
  
