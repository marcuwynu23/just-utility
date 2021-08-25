#include <iostream>
#include "runner.h"

int main(int argc, char const *argv[])
{
	std::string arg1,cmd;

	if(argv[1] != NULL){
		arg1 = argv[1];
		cmd = "del "+ arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("remove a file.");
		peculiar::print("<rm> <file>");
	}
	return 0;
} 
 
