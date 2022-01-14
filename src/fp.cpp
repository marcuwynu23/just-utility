
#include "runner.h"

int main(int argc, char const *argv[])
{
 	// creating source file
	if(argv[1] != NULL){
		string arg1,cmd;
		arg1 = argv[1];
		cmd = "fsutil file layout "+ arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("display file properties.");
		peculiar::print("   fp <file>");
	}
	return 0;
} 

