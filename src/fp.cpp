#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     fp - Display file properties" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     fp [--help | -h] <file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Displays detailed properties and layout information" << endl;
    cout << "     for the specified file using Windows fsutil." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file>  Path to the file" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     fsutil (Windows built-in utility)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     fp main.cpp          Show properties of main.cpp" << endl;
    cout << "     fp C:\\file.txt       Show properties of file.txt" << endl;
    cout << "     fp --help            Show this help" << endl;
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
		cmd = "fsutil file layout "+ arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 

