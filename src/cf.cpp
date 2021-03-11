#include <iostream>

using std::string;
using std::cout;

int main(int argc, char const *argv[])
{
 	// creating source file
	if(argv[1] != NULL){
		string arg1 = argv[1];
		string cmd = "echo. > "+ arg1;
		system(cmd.c_str());
	}else{
		cout <<"creating source file."<<std::endl;
		cout<<"   cf <source file>";
	}

	return 0;
} 

