
#include <iostream>

int main(int argc, char const *argv[])
{
	std::string projectname,language;
	std::string cmd,cmd2,cmd3,cmd4,cmd5,cmd6,cmd7;

	if(argv[1] != NULL && argv[2] != NULL){
		projectname = argv[2];
		language = argv[1];
		if (language == "java"){
			cmd = "md "+projectname+ "\\"+"src";
			system(cmd.c_str());
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			system(cmd2.c_str());
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			system(cmd2.c_str());

		}else if(language == "python"){
			cmd = "md "+projectname+"\\"+"app";
			cmd5 = "cf "+projectname+"\\"+"main.py";
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			system(cmd2.c_str());
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			system(cmd.c_str());
			system(cmd2.c_str());
			system(cmd5.c_str());

		}else if(language == "web") {
			cmd2 = "md "+projectname + "\\screenshots";
			system(cmd2.c_str());
			cmd = "md "+projectname+"\\"+"js";
			system(cmd.c_str());
			cmd6 = 	"md "+projectname+"\\"+"css";
			system(cmd6.c_str());
			cmd7 = 	"md "+projectname+"\\"+"pages";
			system(cmd7.c_str());
			cmd5 = "cf "+projectname+"\\"+"index.html";
			system(cmd5.c_str());
		}
		else {
			cmd = "md "+projectname+"\\"+"src";
			system(cmd.c_str());
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			system(cmd2.c_str());
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			system(cmd2.c_str());
		}
		
		cmd3 = "cf "+projectname + "\\"+"LICENSE";
		cmd4 = "cf "+projectname + "\\"+"README.txt";
		
		system(cmd3.c_str());
		system(cmd4.c_str());
	}else{

		std::cout << "build project structure." << std::endl;
		std::cout << "<ctp> <project-type |language> <project-name>" << std::endl;

	}
	return 0;
} 

