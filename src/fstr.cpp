
#include "runner.h"

int main(int argc, char const *argv[])
{
	string arg1,arg2,cmd1,cmd2;

	if(argv[1] != NULL && argv[2] != NULL ){
		arg1 = argv[1];
		arg2 = argv[2];
		cmd1 = "findstr /O /N /X "+ arg2 + " *."+arg1;
		cmd2 = "findstr /O /N "+ arg2 + " *."+arg1;
		peculiar::print("Exact Result:");
		peculiar::runExe(cmd1);
		peculiar::print("Other Result:");
		peculiar::runExe(cmd2);

	}else{
		peculiar::print("find string in source files in current directory.");
		peculiar::print("<fstr> <source extension> <string>");
	}
	return 0;
} 
