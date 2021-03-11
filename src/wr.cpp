#include <iostream>

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL){
		std::string arg1 = argv[1];
		std::string cmd = "explorer "+ arg1;

		system(cmd.c_str());
	}else{
		std::cout << "open html file in default browser." << std::endl;
		std::cout << "<wr> <html file>" << std::endl;
	}
	return 0;
} 
