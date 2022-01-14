#include "runner.h"

int main(int argc, char const *argv[])
{
 	// creating source file
	if(argv[1] != NULL){
		string arg1,cmd;
		arg1 = argv[1];
		cmd = "echo. > "+ arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("creating source file.");
		peculiar::print("   cf <source file>");
	}
	return 0;
} 

