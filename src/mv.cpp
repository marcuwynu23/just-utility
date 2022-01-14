
#include "runner.h"

int main(int argc, char const *argv[]){
	string arg1,arg2,cmd;

	if(argv[1] != NULL && argv[2]!=NULL){
		arg1 = argv[1];
		arg2 = argv[2];
		cmd = "move "+ arg1 + " "+arg2;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("move a file.");
		peculiar::print("<move> <file> <distination>");
	}
	return 0;
} 
 
