 
#include <iostream>
#include <chrono>
#include <ctime>
#include "header\runner.h"

int main(int argc, char const *argv[])
{
	std::string arg1,arg2;
	std::string cmd1,cmd2,cmd3;

	/*interpret cpp source*/
	if (argv[1] !=NULL){
		arg1 = argv[1];
		arg2 = "out";
		cmd1 = "g++ -o" + arg2+ " " + arg1+".cpp";
		cmd2 = arg2;
		cmd3 = "del out.exe";
		
		auto start = std::chrono::system_clock::now();
		peculiar::runExe(cmd1);
		peculiar::runExe(cmd2);
		peculiar::runExe(cmd3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "\nElapsed_seconds : "  << elapsed_seconds.count() << std::endl;
	}else{
		peculiar::print("interpret cpp source file.");
		peculiar::print("   cppi <sourcefile name> ");
	}
	return 0;
}