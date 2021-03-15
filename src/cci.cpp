 
#include <iostream>
#include <chrono>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	string arg1,arg2;
	string cmd1,cmd2,cmd3;

	/*interpret c source*/
	if (argv[1] !=NULL){
		arg1 = argv[1];
		arg2 = "out";
		cmd1 = "gcc -o" + arg2+ " " + arg1+".c";
		cmd2 = arg2;
		cmd3 = "del out.exe";
		
		auto start = std::chrono::system_clock::now();
		system(cmd1.c_str());
		system(cmd2.c_str());
		system(cmd3.c_str());
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		cout <<"\nElapsed_seconds : " << elapsed_seconds.count() <<endl;
	}else{
		cout <<"interpreting c source file."<<std::endl;
		cout <<"   cci <sourcefile name> ";
	}
	return 0;
}