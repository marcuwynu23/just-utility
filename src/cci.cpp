 
#include <iostream>
#include <chrono>
#include <ctime>
#include "runner.h"


int main(int argc, char const *argv[])
{
	std::string arg1,arg2;
	std::string cmd1,cmd2,cmd3;

	/*interpret c source*/
	if (argv[1] !=NULL){
		arg1 = argv[1];
		arg2 = "out";
		cmd1 = "gcc -o" + arg2+ " " + arg1+".c";
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
		std::cout << "\ncompile time: " << compile_time.count() <<"s" << std::endl;
		std::cout << "running time: " << running_time.count() <<"s" << std::endl;
		
	}else{
		peculiar::print("interpreting c source file.");
		peculiar::print("   cci <sourcefile name> ");
	}
	return 0;
}