// sqlite3 -header test.sqlite3 -init test.sql -batch .exit 
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     sqlt3 - Run SQLite3 source files" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     sqlt3 [--help | -h] <output-file> <source-file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Executes SQL commands from a source file against a SQLite3" << endl;
    cout << "     database file. Creates the database if it doesn't exist." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <output-file>  The SQLite3 database file (.sqlite3)" << endl;
    cout << "     <source-file>  The SQL source file (.sql) to execute" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     sqlite3 (SQLite command-line tool)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     sqlt3 test.db init.sql     Execute init.sql against test.db" << endl;
    cout << "     sqlt3 --help               Show this help" << endl;
}

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        string a = argv[1];
        if (a == "--help" || a == "-h") { showHelp(); return 0; }
    }
    string arg1,arg2,arg3,cmd;
    if(argv[1] != NULL && argv[2] !=NULL){
        arg1 = argv[1];
        arg2 = argv[2];
        cmd = "sqlite3 "+arg1+" -cmd \".read "+arg2+" \" -batch .exit";
        peculiar::runExe(cmd);
    }else{
        showHelp();
    } 
    return 0;
}
