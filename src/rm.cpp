#include <iostream>

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL){
		std::string arg1 = argv[1];
		std::string cmd = "del "+ arg1;

		system(cmd.c_str());
	}else{
		std::cout << "remove a file." << std::endl;
		std::cout << "<rm> <file>" << std::endl;
	}
	return 0;
} 
 
