#include <iostream>
#include <chrono>
#include <ctime>
#include "header\runner.h"


int main(int argc, char const *argv[])
{
	std::string arg1,cmd1,cmd2;
	/*interpret cpp source*/
	if (argv[1] !=NULL){
		arg1 = argv[1];
		cmd1 = "javac " + arg1+ ".java && java " + arg1;
		cmd2 = "del *.class";

		auto start = std::chrono::system_clock::now();
		peculiar::runExe(cmd1);
		peculiar::runExe(cmd2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "\nElapsed_seconds : "  << elapsed_seconds.count() << std::endl;
		
	}else{
		peculiar::print("interpret java source file.");
		peculiar::print("jvi <source file name> ");
	}
	return 0;
}