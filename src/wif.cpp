
#include "runner.h"

int main(int argc, char const *argv[]){
	string profile,cmd;
	cmd = "netsh wlan show profile";
	peculiar::runExe(cmd);
	cout << "Enter profile: ";
	cin >> profile;
	cmd = "netsh wlan show profile "+profile+" key=clear";
	peculiar::runExe(cmd);
	return 0;
} 
 
 
