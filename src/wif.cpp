#include <iostream>
#include "runner.h"

int main(int argc, char const *argv[]){
	std::string profile,cmd;
	cmd = "netsh wlan show profile";
	peculiar::runExe(cmd);
	std::cout << "Enter profile: ";
	std::cin >> profile;
	cmd = "netsh wlan show profile "+profile+" key=clear";
	peculiar::runExe(cmd);
	return 0;
} 
 
 
