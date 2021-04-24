#include <iostream>
#include <chrono>
#include <ctime>
#include "header\runner.h"


int main(int argc, char const *argv[])
{
	std::string arg1,cmd1,cmd2,cmd3;
	/*interpret cpp source*/
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

		std::cout << "\ncompile time: " << compile_time.count() <<"s" << std::endl;
		std::cout << "running time: " << running_time.count() <<"s" << std::endl;
	}else{
		peculiar::print("interpret java source file.");
		peculiar::print("jvi <source file name> ");
	}
	return 0;
}