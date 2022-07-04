
#include "runner.h"

int main(int argc, char const *argv[])
{
	string projectname,language;
	string cmd,cmd2,cmd3,cmd4,cmd5,cmd6,cmd7,cmd8;

	if(argv[1] != NULL && argv[2] != NULL)
	{
		projectname = argv[2];
		language = argv[1];
		if (language == "java")
		{
			cmd = "md "+projectname+ "\\"+"src";
			peculiar::runExe(cmd);
			cmd2 = "md "+projectname + "\\docs\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\docs\\docs.html";
			peculiar::runExe(cmd2);

		}
		else if(language == "python")
		{
			cmd = "md "+projectname+"\\"+"app";
			cmd5 = "cf "+projectname+"\\"+"main.py";
			cmd8 = "cf "+projectname+"\\"+"setup.py";
			cmd2 = "md "+projectname + "\\docs\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\docs\\docs.html";
			peculiar::runExe(cmd);
			peculiar::runExe(cmd2);
			peculiar::runExe(cmd5);
			peculiar::runExe(cmd8);

		}
		else if(language == "web") 
		{
			cmd2 = "md "+projectname + "\\screenshots";
			peculiar::runExe(cmd2);
			cmd = "md "+projectname+"\\"+"static\\js";
			peculiar::runExe(cmd);
			cmd6 = 	"md "+projectname+"\\"+"static\\css";
			peculiar::runExe(cmd6);
			cmd7 = 	"md "+projectname+"\\"+"templates";
			peculiar::runExe(cmd7);
			cmd5 = "cf "+projectname+"\\"+"index.html";
			peculiar::runExe(cmd5);
		}
		else if(language == "js-web-app") 
		{
			cmd = "md "+projectname+"\\"+"public\\js";
			peculiar::runExe(cmd);
			cmd = "cf "+projectname+"\\"+"public\\js\\script.js";
			peculiar::runExe(cmd);
			cmd = "md "+projectname+"\\"+"public\\assets\\img";
			peculiar::runExe(cmd);
			cmd6 = 	"md "+projectname+"\\"+"public\\css";
			peculiar::runExe(cmd6);
			cmd6 = 	"cf "+projectname+"\\"+"public\\css\\style.css";
			peculiar::runExe(cmd6);
			cmd7 = 	"md "+projectname+"\\"+"view";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"view\\initials";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"view\\features";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"router";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"router\\router.js";
			peculiar::runExe(cmd7);		
			cmd7 = 	"md "+projectname+"\\"+"controller";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"controller\\controller.js";
			peculiar::runExe(cmd7);			
			cmd7 = 	"md "+projectname+"\\"+"database";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"database\\database.js";
			peculiar::runExe(cmd7);
			cmd5 = "md "+projectname+"\\"+"constant";
			peculiar::runExe(cmd5);		
			cmd5 = "cf "+projectname+"\\"+"constant\\constants.js";
			peculiar::runExe(cmd5);		
			cmd5 = "cf "+projectname+"\\"+"app.js";
			peculiar::runExe(cmd5);
		}

		else if(language == "php-web-app") 
		{
			
			cmd = "md "+projectname+"\\"+"public\\js";
			peculiar::runExe(cmd);
			cmd = "cf "+projectname+"\\"+"public\\js\\script.js";
			peculiar::runExe(cmd);
			cmd = "md "+projectname+"\\"+"public\\assets\\img";
			peculiar::runExe(cmd);
			cmd6 = 	"md "+projectname+"\\"+"public\\css";
			peculiar::runExe(cmd6);
			cmd6 = 	"cf "+projectname+"\\"+"public\\css\\style.css";
			peculiar::runExe(cmd6);
			cmd7 = 	"md "+projectname+"\\"+"view";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"view\\initials";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"view\\features";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"router";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"router\\router.php";
			peculiar::runExe(cmd7);			
			cmd7 = 	"md "+projectname+"\\"+"database";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"database\\database.php";
			peculiar::runExe(cmd7);
			cmd7 = 	"md "+projectname+"\\"+"controller";
			peculiar::runExe(cmd7);
			cmd7 = 	"cf "+projectname+"\\"+"controller\\controller.php";
			peculiar::runExe(cmd7);
			cmd5 = "md "+projectname+"\\"+"constant";
			peculiar::runExe(cmd5);		
			cmd5 = "cf "+projectname+"\\"+"constant\\constants.php";
			peculiar::runExe(cmd5);		
			cmd5 = "cf "+projectname+"\\"+"app.php";
			peculiar::runExe(cmd5);
		}
		else if(language == "c" || language == "cpp" || language == "c++") 
		{
			cmd = "md "+projectname+"\\"+"src\\include";
			peculiar::runExe(cmd);
			cmd2 = "cf "+projectname + "\\makefile";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\docs\\docs.html";
			peculiar::runExe(cmd2);
		}
		else 
		{
			cmd = "md "+projectname+"\\"+"src";
			peculiar::runExe(cmd);
			cmd2 = "md "+projectname + "\\docs\\screenshots";
			peculiar::runExe(cmd2);
			cmd2 = "cf "+projectname+"\\docs\\docs.html";
			peculiar::runExe(cmd2);
		}
		
		cmd3 = "cf "+projectname + "\\"+"LICENSE";
		cmd4 = "cf "+projectname + "\\"+"README.md";
		
		peculiar::runExe(cmd3);
		peculiar::runExe(cmd4);
	}
	else
	{
		peculiar::print("build project structure.");
		peculiar::print("ctp <project-type | language > <project-name>");
		peculiar::print("java							java application");
		peculiar::print("python							python application");
		peculiar::print("js-web-app						nodejs web application");
		peculiar::print("php-web-app						php web application");
		peculiar::print("c|c++|cpp						c|c++ application");
		peculiar::print("web							website");
		peculiar::print("[any]							anything");
	}
	return 0;
} 

