#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	string arg1,arg2,cmd;

	if(argv[1] != NULL && argv[2]!=NULL){
		arg1 = argv[1];
		arg2 = argv[2];
		cmd = "move "+ arg1 + " "+arg2;
		system(cmd.c_str());
	}else{
		cout << "move a file." << endl;
		cout << "<move> <file> <distination>" << endl;
	}
	return 0;
} 
 
