#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     mv - Move or rename a file" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     mv [--help | -h] <source> <destination>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Moves a file from the source path to the destination path." << endl;
    cout << "     Can also be used to rename a file. Uses the Windows 'move' command." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <source>       Path to the file to move" << endl;
    cout << "     <destination>  Destination path or directory" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     None (uses built-in Windows commands)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     mv file.txt ..\\            Move file.txt to parent directory" << endl;
    cout << "     mv old.txt new.txt          Rename old.txt to new.txt" << endl;
    cout << "     mv --help                   Show this help" << endl;
}

int main(int argc, char const *argv[]){
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string arg1,arg2,cmd;

	if(argv[1] != NULL && argv[2]!=NULL){
		arg1 = argv[1];
		arg2 = argv[2];
		cmd = "move "+ arg1 + " "+arg2;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 
  
