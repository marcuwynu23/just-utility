
#include "runner.h"


int main(int argc, char const *argv[])
{
	std::string arg1,cmd;
	if(argv[1] != NULL){
		arg1 = argv[1];
		cmd = "explorer "+ arg1;
		peculiar::runExe(cmd);
	}else{
		peculiar::print("open html file in default browser.");
		peculiar::print("<wr> <html file| URL address>");
	}
	return 0;
} 
