
#include "runner.h"

const string RESET = "\u001B[0;0m";
const string GREEN = "\u001B[0;92m";
const string WHITE_BOLD = "\u001B[1;97m";

int main(int argc, char const *argv[])
{
	string cmd,initial;
	cout <<GREEN+"";
	peculiar::runExe("cls");
	cout << GREEN+"Just Utility v0.0.2" << endl;
	cout << GREEN+"jvi"+WHITE_BOLD+"		java false interpreter(java jdk)." << endl;
	cout << GREEN+"cci"+WHITE_BOLD+"		c false interpreter(required mingw)." << endl;
	cout << GREEN+"cppi"+WHITE_BOLD+"		c++ false interpreter(required mingw)." << endl;
	cout << GREEN+"csi"+WHITE_BOLD+"		c# false interpreter." << endl;
	cout << GREEN+"wr"+WHITE_BOLD+"		browse html file." << endl;
	cout << GREEN+"xr"+WHITE_BOLD+"		open file explorer in current directory." << endl;
	cout << GREEN+"cf"+WHITE_BOLD+"		create file." << endl;
	cout << GREEN+"ctp"+WHITE_BOLD+"		create projects." << endl;
	cout << GREEN+"jpb"+WHITE_BOLD+"		java project builder." << endl;
	cout << GREEN+"ls"+WHITE_BOLD+" 		listing files." << endl;
	cout << GREEN+"mv"+WHITE_BOLD+" 		moving a file." << endl;
	cout << GREEN+"rm"+WHITE_BOLD+" 		remove a file." << endl;
	cout << GREEN+"snip"+WHITE_BOLD+" 		open window snipping tools." << endl;
	cout << GREEN+"fstr"+WHITE_BOLD+"		find string in a files." << endl;
	cout << GREEN+"fp"+WHITE_BOLD+"         	display file properties." << endl;
	cout << GREEN+"cat"+WHITE_BOLD+"		display file content." << endl;
	cout << GREEN+"dt"+WHITE_BOLD+"         	display date and time." << endl;
	cout << GREEN+"lc"+WHITE_BOLD+"         	location file or directory." << endl;
	cout << GREEN+"sqlt3"+WHITE_BOLD+"      	run sqlite3 source file." << endl;
	cout << GREEN+"wif"+WHITE_BOLD+"         	show wifi profile information" << endl;
	cout << GREEN+"droid"+WHITE_BOLD+"      	run droiddroid commandline" << endl;
	return 0;
} 
