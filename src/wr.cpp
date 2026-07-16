#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     wr - Open a URL or file in the default browser" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     wr [--help | -h] <url | file>" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Opens the specified URL or HTML file in the system's" << endl;
    cout << "     default web browser using Windows 'explorer' command." << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "ARGUMENTS" << endl;
    cout << "     <url | file>  A URL (e.g., https://example.com) or path" << endl;
    cout << "                   to an HTML file to open in the browser" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     Default web browser (Windows 'explorer' command opens URLs)" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     wr https://google.com    Open Google" << endl;
    cout << "     wr index.html            Open index.html in browser" << endl;
    cout << "     wr --help                Show this help" << endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		string a = argv[1];
		if (a == "--help" || a == "-h") { showHelp(); return 0; }
	}
	std::string arg1,cmd;
	if(argv[1] != NULL){
		arg1 = argv[1];
		cmd = "explorer "+ arg1;
		peculiar::runExe(cmd);
	}else{
		showHelp();
	}
	return 0;
} 
