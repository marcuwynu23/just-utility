/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     jr - Run JAR files from C:/jar/" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     jr [--help | -h] <file-name> [args]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Runs a JAR file located in the C:/jar/ directory." << endl;
    cout << "     The .jar extension is appended automatically." << endl;
    cout << "     Optional arguments are passed to the JAR at runtime." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <file-name>  Name of the JAR file (without .jar extension)" << endl;
    cout << "     [args]       Optional arguments passed to the JAR" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     java (Java Runtime Environment)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     jr myapp               Run C:/jar/myapp.jar" << endl;
    cout << "     jr myapp --verbose     Run with arguments" << endl;
    cout << "     jr --help              Show this help" << endl;
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

        default_path = "C:/jar/";
        cmd = "java -jar  "+default_path+arg1+".jar"+" "+arg2;
        peculiar::runExe(cmd);
    }else{
        showHelp();
    }
}