#include <iostream>
#include "runner.h"



int main(int argc, char const *argv[])
{
 	// creating source file
	if(argv[1] != NULL){
		std::string arg1,cmd;
		arg1 = argv[1];
		cmd = "dir /B /S "+arg1+" | findstr "+arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("locate file.");
		peculiar::print("lc <file>");
	}
	return 0;
} 

