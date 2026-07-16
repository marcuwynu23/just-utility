#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     pyr - Run Python scripts from C:/scripts/py/" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     pyr [--help | -h] <file-name> [args]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Runs a Python script located in the C:/scripts/py/ directory." << endl;
    cout << "     The .py extension is appended automatically." << endl;
    cout << "     Optional arguments are passed to the script at runtime." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file-name>  Name of the Python script (without .py extension)" << endl;
    cout << "     [args]       Optional arguments passed to the script" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     python (Python 3 interpreter)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     pyr myscript          Run C:/scripts/py/myscript.py" << endl;
    cout << "     pyr myscript --test   Run with arguments" << endl;
    cout << "     pyr --help            Show this help" << endl;
}

int main(int argc, char const *argv[]){
    if (argc > 1) {
        string a = argv[1];
        if (a == "--help" || a == "-h") { showHelp(); return 0; }
    }
    if(argv[1] != NULL){
        string arg1,arg2,default_path,cmd;

        arg1 = argv[1];
        arg2 = argv[2];

        default_path = "C:/scripts/py/";
        cmd = "python "+default_path+arg1+".py"+" "+arg2;
        peculiar::runExe(cmd);
    }else{
        showHelp();
    }
}