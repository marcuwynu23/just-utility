#include <chrono>
#include <ctime>
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     jvi - Java source code interpreter (compile + run)" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     jvi [--help | -h] <sourcefile>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Compiles and runs a Java source file in a single step." << endl;
    cout << "     The source file is compiled with javac, executed with" << endl;
    cout << "     java, and the resulting .class files are cleaned up." << endl;
    cout << "     Shows compile time and execution time after running." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <sourcefile>  Name of the Java source file (without .java extension)" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     javac (Java Development Kit)" << endl;
    cout << "     java (Java Runtime Environment)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     jvi Hello          Compile and run Hello.java" << endl;
    cout << "     jvi --help         Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string arg1,cmd1,cmd2,cmd3;
	
	if (argv[1] !=NULL){
		arg1 = argv[1];
		cmd1 = "javac " + arg1+ ".java";
		cmd2 = "java " + arg1;
		cmd3 = "del *.class";

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