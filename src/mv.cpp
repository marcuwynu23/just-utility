#include <iostream>

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL && argv[2]!=NULL){
		std::string arg1 = argv[1];
		std::string arg2 = argv[2];
		std::string cmd = "move "+ arg1 + " "+arg2;
		system(cmd.c_str());
	}else{
		std::cout << "move a file." << std::endl;
		std::cout << "<move> <file> <distination>" << std::endl;
	}
	return 0;
} 
 
