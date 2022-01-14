
#include "runner.h"

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL){
		string arg1,cmd;
		arg1 = argv[1];
		cmd = "type "+ arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("display source file.");
		peculiar::print("   cat <source file>");
	}
	return 0;
}

