#include <iostream>

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL && argv[2] != NULL ){
		std::string arg1 = argv[1];
		std::string arg2 = argv[2];
		std::string cmd1 = "findstr /O /N /X "+ arg2 + " *."+arg1;
		std::string cmd2 = "findstr /O /N "+ arg2 + " *."+arg1;
		
		std::cout << "Exact Result:" <<std::endl;
		system(cmd1.c_str());
		std::cout << "" <<std::endl;
		std::cout << "Other Result:" <<std::endl;
		system(cmd2.c_str());

	}else{
		std::cout << "find string in source files in current directory." << std::endl;
		std::cout << "<fstr> <source extension> <string>" << std::endl;
	}
	return 0;
} 
