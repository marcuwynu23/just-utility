
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;


const string RESET = "\u001B[0;0m";
const string GREEN_BRIGHT = "\u001B[0;92m";
const string WHITE_BOLD = "\u001B[1;92m";

void  runExe(std::string value)
{
	std::mutex m;
	std::thread t{[&]
		{
			std::lock_guard<std::mutex> lock{m};
			system(value.c_str());
		}
	};
	t.join();
}

void show(){
	cout <<WHITE_BOLD+" DroidDroidHelper (Android Development on Android Device Helper)" << endl;
	cout <<GREEN_BRIGHT+"help"+RESET+ "     show this message" << endl;
	cout <<GREEN_BRIGHT+"cls"+RESET+ "      clear screen" << endl;
	cout <<GREEN_BRIGHT+"net"+RESET+"       connect via net(default port: 7575)" << endl;
	cout <<GREEN_BRIGHT+"tcp"+RESET+"       start tcp server" << endl;
	cout <<GREEN_BRIGHT+"usb"+RESET+"       connect via usb" << endl;
	cout <<GREEN_BRIGHT+"ide"+RESET+"       open ide on android" << endl;
	cout <<GREEN_BRIGHT+"pt "+RESET+"       enable/disable pointer location of devices" << endl;
	cout <<GREEN_BRIGHT+"th "+RESET+"       enable/disable show touches " << endl;
	cout <<GREEN_BRIGHT+"cmd"+RESET+"       open commandline Terminal" << endl;
	cout <<GREEN_BRIGHT+"e  "+RESET+"       open text Editor" << endl;
	cout <<GREEN_BRIGHT+"lsp"+RESET+"       list projects" << endl;
	cout <<GREEN_BRIGHT+"psa"+RESET+"       push projects to remote android device directory" << endl;
	cout <<GREEN_BRIGHT+"pla"+RESET+"       pull projects from remote android device directory" << endl;
	cout <<GREEN_BRIGHT+"ps "+RESET+"       push a project to remote android device directory" << endl;
	cout <<GREEN_BRIGHT+"pl "+RESET+"       pull a project from remote android device directory" << endl;
	cout <<GREEN_BRIGHT+"dpl"+RESET+"       delete project in the local directory" << endl;
	cout <<GREEN_BRIGHT+"dpr"+RESET+"       delete project in the remote directory" << endl;
	cout <<GREEN_BRIGHT+"ut "+RESET+"       uninstall android application from android device" << endl;
	cout <<GREEN_BRIGHT+"it "+RESET+"       install android package to the android device" << endl;
	cout <<GREEN_BRIGHT+"ra "+RESET+"       run android application from android device" << endl;
	cout <<GREEN_BRIGHT+"ca "+RESET+"       close android application from android device" << endl;
	cout <<GREEN_BRIGHT+"sc "+RESET+"       save and compile " << endl;
	cout <<GREEN_BRIGHT+"ir "+RESET+"       install and run" << endl;
}


void openShell(){
	system("adb shell");
}


void connectViaTCP(){
	string PORT;
	cout << "Enter port: ";
	getline(cin,PORT);
	runExe("adb tcpip "+PORT);
	

}

void connectNet(){
	string IP,PORT;
	cout << "Enter Ip: ";
	getline(cin,IP);
	cout << "Enter port: ";
	getline(cin,PORT);
	runExe("adb connect "+IP+":"+PORT);
}

void connectViaUSB(){
	runExe("adb usb ");
}
void openIDE(string ANDROID_IDE){
	runExe("adb shell monkey -p "+ANDROID_IDE+" 1 > nul");
}
void pointerLocation(){
	string VALUE;
	VALUE = "0";
	cout << "Enter value: ";
	getline(cin,VALUE);
	runExe("adb shell settings put system pointer_location "+VALUE);
}

void showTouch(){
	string VALUE;
	VALUE = "0";
	cout << "Enter value: ";
	getline(cin,VALUE);
	runExe("adb shell settings put system show_touches "+VALUE);
}

void openCMD(){
	runExe("start conEmu -cmd -new_console:n ");
}
void openEditor(string LOCAL_PATH,string WORK_DIR){
	runExe("subl "+LOCAL_PATH+"\\"+WORK_DIR);
}
void lsProjects(string LOCAL_PATH,string WORK_DIR){
	runExe("dir /O-D /B "+LOCAL_PATH+"\\"+WORK_DIR);
}

void pullprojects(string LOCAL_PATH,string REMOTE_PATH,string WORK_DIR){
	cout <<" pull projects from "+REMOTE_PATH+"/"+WORK_DIR+"... " << endl;
	runExe("adb pull "+REMOTE_PATH+"/"+WORK_DIR+" "+LOCAL_PATH);
	cout <<" projects pulled. " << endl;

}

void pullproject(string LOCAL_PATH,string REMOTE_PATH,string WORK_DIR){
	string PROJECT_NAME;
	cout << "Enter project name: ";
	getline(cin,PROJECT_NAME);
	runExe("rmdir /S /Q "+LOCAL_PATH+"\\"+WORK_DIR+"\\"+PROJECT_NAME);
	cout << "pull "+PROJECT_NAME+" from "+REMOTE_PATH+"/"+WORK_DIR+"/"+PROJECT_NAME+"..." << endl;
	runExe("adb pull "+REMOTE_PATH+"/"+WORK_DIR+"/"+PROJECT_NAME+" "+LOCAL_PATH+"\\"+WORK_DIR);
	cout << "echo project "+PROJECT_NAME+" pulled." << endl;

}

void pushprojects(string LOCAL_PATH,string REMOTE_PATH,string WORK_DIR){
	cout << "echo pushing projects to remote directory..." << endl;
	runExe("adb push "+LOCAL_PATH+"\\"+WORK_DIR+" "+REMOTE_PATH);
	cout << "echo projects pushed." << endl;
}


void pushproject(string LOCAL_PATH,string REMOTE_PATH,string WORK_DIR){
	string PROJECT_NAME;
	cout << "Enter project name: ";
	getline(cin,PROJECT_NAME);
	runExe("adb shell rm -rf "+REMOTE_PATH+"/"+WORK_DIR+"/"+PROJECT_NAME);
	cout << "echo pushing " +PROJECT_NAME +" to remote directory... " << endl;
	runExe("adb push "+LOCAL_PATH+"\\"+WORK_DIR+"\\"+PROJECT_NAME+" "+REMOTE_PATH+"/"+WORK_DIR);

}

void deleteProjectLocal(string LOCAL_PATH,string WORK_DIR){
	string PROJECT_NAME;
	cout << "Enter project name: ";
	getline(cin,PROJECT_NAME);
	runExe("rmdir /Q /S "+LOCAL_PATH+"/"+WORK_DIR+"/"+PROJECT_NAME);
}


void deleteProjectRemote(string REMOTE_PATH, string WORK_DIR){
	string PROJECT_NAME;
	cout << "Enter project name: ";
	getline(cin,PROJECT_NAME);
	runExe("adb shell rm -rf "+REMOTE_PATH+"/"+WORK_DIR+"/"+PROJECT_NAME);
}

void unistallapp(){
	string PACKAGE;
	cout << "Enter package: ";
	getline(cin,PACKAGE);
	runExe("adb uninstall "+ PACKAGE);
}

void installapp(){
	string PACKAGE_NAME;
	cout << "Enter package name: ";
	getline(cin,PACKAGE_NAME);
	runExe("adb install "+ PACKAGE_NAME);

}


void runApplication(){
	string PACKAGE;
	cout << "Enter package: ";
	getline(cin,PACKAGE);
	runExe("adb shell monkey -p "+ PACKAGE +" 1 > nul");
}

void closeApplication(){
	string PACKAGE;
	cout << "Enter package: ";
	getline(cin,PACKAGE);
	runExe("adb shell am force-stop "+PACKAGE);
}

void saveCompile(string COM_X,string COM_Y){
	runExe("adb shell input tap "+COM_X+" "+COM_Y);
}

void installRun(string RUN_X,string RUN_Y){
	runExe("adb shell input tap "+RUN_X+" "+RUN_Y);
}


int main(int argc, char const *argv[])
{
	string REMOTE_PATH = argv[1];
	string LOCAL_PATH = argv[2];
	string WORK_DIR = argv[3];
	string CMD_TERM = argv[4];
	string EDITOR = argv[5];
	string ANDROID_IDE = argv[6];
	string COM_X = argv[7];
	string COM_Y = argv[8];
	string RUN_X = argv[9];
	string RUN_Y = argv[10];


	// cout << REMOTE_PATH+" "+LOCAL_PATH + " "+ WORK_DIR+ " ";
	// cout << CMD_TERM+ " "+ EDITOR+ " "+ ANDROID_IDE+ " ";
	// cout << COM_X + " "+ COM_Y+ " "+ RUN_X + " "+ RUN_Y;
	// exit(0);
	// string REMOTE_PATH = "/storage/emulated/0/";
	// string LOCAL_PATH = "C:\\Users\\admin\\Desktop\\Dev";
	// string WORK_DIR = "JavaNIDE";
	// string CMD_TERM = "cmd";
	// string EDITOR = "subl";
	// string ANDROID_IDE = "com.duy.compiler.javanide";
	// string COM_X = "265";
	// string COM_Y = "109";
	// string RUN_X = "632";
	// string RUN_Y = "1457";
	string CHOICE;
	cout <<GREEN_BRIGHT+"hello.-)"+RESET+" ";
	runExe("cls");
	while(1){
		cout <<GREEN_BRIGHT+"droid >"+RESET+" ";
		getline(cin,CHOICE);
		if (CHOICE == "help"){
			show();
		}
		else if(CHOICE == "tcp"){
			connectViaTCP();
		}
		else if(CHOICE == "usb"){
			connectViaUSB();
		}
		else if(CHOICE == "net"){
			connectNet();
		}
		else if(CHOICE == "ide"){
			openIDE(ANDROID_IDE);
		}
		else if(CHOICE == "th"){
			showTouch();
		}
		else if(CHOICE == "pt"){
			pointerLocation();
		}
		else if(CHOICE == "cmd"){
			openCMD();
		}
		else if(CHOICE == "e"){
			openEditor(LOCAL_PATH,WORK_DIR);
		}
		else if(CHOICE == "lsp"){
			lsProjects(LOCAL_PATH,WORK_DIR);
		}
		else if(CHOICE == "psa"){
			pushprojects(LOCAL_PATH,REMOTE_PATH,WORK_DIR);
		}
		else if(CHOICE == "ps"){
			pushproject(LOCAL_PATH,REMOTE_PATH,WORK_DIR);
		}
		else if(CHOICE == "pla"){
			pullprojects(LOCAL_PATH,REMOTE_PATH,WORK_DIR);
		}
		else if(CHOICE == "pl"){
			pullproject(LOCAL_PATH,REMOTE_PATH,WORK_DIR);
		}
		else if(CHOICE == "dpl"){
			deleteProjectLocal(LOCAL_PATH,WORK_DIR);
		}
		else if(CHOICE == "dpr"){
			deleteProjectRemote(REMOTE_PATH,WORK_DIR);
		}
		else if(CHOICE == "ia"){
			installapp();
		}
		else if(CHOICE == "ra"){
			runApplication();
		}
		else if(CHOICE == "ca"){
			closeApplication();
		}
		else if(CHOICE == "sc"){
			saveCompile(COM_X,COM_Y);
		}
		else if(CHOICE == "ir"){
			installRun(RUN_X,RUN_Y);	
		}
		else if(CHOICE == "sh"){
			openShell();
		}else if(CHOICE == "exit"){
			exit(0);
		}else if (CHOICE == "cls"){
			system("cls");
		}else{
			cout << "wrong command. try help " << endl;
		}
	}
	return 0;
}

