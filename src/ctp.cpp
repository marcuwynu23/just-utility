// cmd:
// md "projectname"
// md projectname\src
// md projectname\dist
// md projectname\plan
// cf LICENSE
// cf README.txt

#include <iostream>

int main(int argc, char const *argv[])
{
	if(argv[1] != NULL && argv[2] != NULL){
		std::string projectname = argv[2];
		std::string language = argv[1];
		if (language == "java"){

			std::string cmd = "md "+projectname+ "\\"+"src";
			system(cmd.c_str());
		
		}else if(language == "python"){
			
			std::string cmd = "md "+projectname+"\\"+"app";
			std::string cmd5 = "cf "+projectname+"\\"+"main.py";
			system(cmd.c_str());
			system(cmd5.c_str());
		
		}else if(language == "web") {
			
			std::string cmd = "md "+projectname+"\\"+"js";
			system(cmd.c_str());
			std::string cmd6 = 	"md "+projectname+"\\"+"css";
			system(cmd6.c_str());
			std::string cmd7 = 	"md "+projectname+"\\"+"pages";
			system(cmd7.c_str());
			std::string cmd5 = "cf "+projectname+"\\"+"index.html";
			system(cmd5.c_str());
		}
		else {
			std::string cmd = 	"md "+projectname+"\\"+"src";
			system(cmd.c_str());
		}
		std::string cmd2 = "md "+projectname + "\\"+"plan";
		std::string cmd3 = "cf "+projectname + "\\"+"LICENSE";
		std::string cmd4 = "cf "+projectname + "\\"+"README.txt";
		
		system(cmd2.c_str());
		system(cmd3.c_str());
		system(cmd4.c_str());
	}else{
	
		std::cout << "build project structure." << std::endl;
		std::cout << "<ctp> <project-type |language> <project-name>" << std::endl;
	
	}
	return 0;
} 

