#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	string arg1,cmd;

	if(argv[1] != NULL){
		string arg1 = argv[1];
		string cmd = "del "+ arg1;
		system(cmd.c_str());
	}else{
		cout << "remove a file." << endl;
		cout << "<rm> <file>" << endl;
	}
	return 0;
} 
 
