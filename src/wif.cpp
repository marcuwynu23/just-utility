#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     wif - Show WiFi profile information" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     wif [--help | -h]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Lists all saved WiFi profiles on the system and then" << endl;
    cout << "     prompts you to enter a profile name to view its details," << endl;
    cout << "     including the Wi-Fi password (key) in clear text." << endl;
    cout << "     Uses the Windows 'netsh wlan' command internally." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     netsh (Windows built-in networking utility)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     wif                 Show WiFi profiles and details" << endl;
    cout << "     wif --help          Show this help" << endl;
}

int main(int argc, char const *argv[]){
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	string profile,cmd;
	cmd = "netsh wlan show profile";
	peculiar::runExe(cmd);
	cout << "Enter profile: ";
	getline( cin,profile);
	cmd = "netsh wlan show profile \""+profile+"\" key=clear";
	peculiar::runExe(cmd);
	return 0;
} 
  
 
