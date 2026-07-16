/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */

#include <chrono>
#include <ctime>
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     csi - C# source code interpreter (compile + run)" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     csi [--help | -h] <sourcefile>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Compiles and runs a C# source file in a single step." << endl;
    cout << "     The source file is compiled with the C# compiler (csc), executed," << endl;
    cout << "     and the resulting binary is cleaned up automatically." << endl;
    cout << "     Shows compile time and execution time after running." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <sourcefile>  Name of the C# source file (without .cs extension)" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     csc (C# compiler, part of .NET Framework SDK / Roslyn)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     csi program         Compile and run program.cs" << endl;
    cout << "     csi --help          Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string arg1,arg2;
	string cmd1,cmd2,cmd3;

	if (argv[1] !=NULL){
		
		arg1 = argv[1];
		arg2 = "out";
		cmd1 = "csc /out:out.exe "+arg1+".cs";
		cmd2 = arg2;
		cmd3 = "del out.exe";
		
		auto s1 = std::chrono::system_clock::now();
		peculiar::runExe(cmd1);
		auto e1 = std::chrono::system_clock::now();
		auto s2 = std::chrono::system_clock::now();
		peculiar::runExe(cmd2);
		auto e2 = std::chrono::system_clock::now();
		peculiar::runExe(cmd3);
		
		std::chrono::duration<double> compile_time = e1-s1;
		std::chrono::duration<double> running_time = e2-s2;

		cout << "\ncompile time: " << compile_time.count() <<"s" << endl;
		cout << "running time: " << running_time.count() <<"s" << endl;
	
	}else{
		showHelp();
	}
	return 0;
}