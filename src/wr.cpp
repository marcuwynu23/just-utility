#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string arg1,cmd;
	if(argv[1] != NULL){
		arg1 = argv[1];
		cmd = "explorer "+ arg1;
		system(cmd.c_str());
	}else{
		cout << "open html file in default browser." << endl;
		cout << "<wr> <html file>" << endl;
	}
	return 0;
} 
