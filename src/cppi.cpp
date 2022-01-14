#include <chrono>
#include <ctime>
#include "runner.h"

int main(int argc, char const *argv[])
{
	string arg1,arg2;
	string cmd1,cmd2,cmd3;

	/*interpret cpp source*/
	if (argv[1] !=NULL){
		
		arg1 = argv[1];
		arg2 = "out";
		cmd1 = "g++ -o" + arg2+ " " + arg1+".cpp";
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
		peculiar::print("interpret cpp source file.");
		peculiar::print("   cppi <sourcefile name> ");
	}
	return 0;
}