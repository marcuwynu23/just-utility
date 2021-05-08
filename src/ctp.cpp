#include <iostream>
#include "header\runner.h"


int main(int argc, char const *argv[])
{
	std::string projectname,language;
	std::string cmd,cmd2,cmd3,cmd4,cmd5,cmd6,cmd7,cmd8;

	if(argv[1] != NULL && argv[2] != NULL)
	{
		projectname = argv[2];
		language = argv[1];
		if (language == "java")
		{
			cmd = "md "+projectname+ "\\"+"src";
			peculiar::runExe(cmd);
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			peculiar::runExe(cmd2);

		}
		else if(language == "python")
		{
			cmd = "md "+projectname+"\\"+"app";
			cmd5 = "cf "+projectname+"\\"+"main.py";
			cmd8 = "cf "+projectname+"\\"+"setup.py";
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			peculiar::runExe(cmd);
			peculiar::runExe(cmd2);
			peculiar::runExe(cmd5);
			peculiar::runExe(cmd8);

		}
		else if(language == "web") 
		{
			cmd2 = "md "+projectname + "\\screenshots";
			peculiar::runExe(cmd2);
			cmd = "md "+projectname+"\\"+"js";
			peculiar::runExe(cmd);
			cmd6 = 	"md "+projectname+"\\"+"css";
			peculiar::runExe(cmd6);
			cmd7 = 	"md "+projectname+"\\"+"pages";
			peculiar::runExe(cmd7);
			cmd5 = "cf "+projectname+"\\"+"index.html";
			peculiar::runExe(cmd5);
		}
		else 
		{
			cmd = "md "+projectname+"\\"+"src";
			peculiar::runExe(cmd);
			cmd2 = "md "+projectname + "\\doc\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\doc\\docs.html";
			peculiar::runExe(cmd2);
		}
		
		cmd3 = "cf "+projectname + "\\"+"LICENSE";
		cmd4 = "cf "+projectname + "\\"+"README.txt";
		
		peculiar::runExe(cmd3);
		peculiar::runExe(cmd4);
	}
	else
	{
		peculiar::print("build project structure.");
		peculiar::print("ctp <project-type | language > <project-name>");

	}
	return 0;
} 

