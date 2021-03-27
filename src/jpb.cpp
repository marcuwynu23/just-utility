#include <iostream>
#include "header\runner.h"

using std::cout;
using std::endl;

void show_help(){
	cout << "jpb <option>" << endl;
	cout << "option: " << endl;
	cout << "--init                                   initialize project build requirement for creating jar archive." << endl;
	cout << "--md <package/folders>                   create package or nested forder." << endl;
	cout << "--cf <package/folders> <source-file>     create file inside package or nested folders." << endl;
	cout << "--compile                                compiling to jar archive." << endl;
	cout << "--compile-deps                           compiling to jar archive with dependencies." << endl;
	cout << "--run                                    run jar project." << endl;
}


std::string replace(std::string str,std::string ch,std::string name){
	size_t pos = 0;
	if(!ch.empty()){
		while((pos=str.find(ch,pos)) != std::string::npos){
			str.replace(pos,ch.length(),name);
			pos += name.length();
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{

	std::string option,sources,depends,classes,manifest,output,package_name,file_name;
	std::string cmd1,cmd2,cmd3,cmd4,cmd5;

	if(argv[1] != NULL)
	{
		option = argv[1];
		if(option == "--init")
		{
			peculiar::runExe("md build dist");
			peculiar::runExe("echo. >> build\\classes.list");
			peculiar::runExe("echo. >> build\\sources.list");
			peculiar::runExe("echo. >> build\\depends.list");
			peculiar::runExe("echo. >> Manifest.MF");

		}else if (option == "--compile")
		{

			sources= "@build\\sources.list";
			classes= "@build\\classes.list";
			manifest="Manifest.MF";
			output="project.jar";
			cmd1 = "javac -d . " + sources;
			cmd2 = "md dist";
			cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
			cmd4 = "rd /Q /S com";

			peculiar::runExe(cmd1);
			peculiar::runExe(cmd2);
			peculiar::runExe(cmd3);
			peculiar::runExe(cmd4);
			
		}
		else if (option == "--compile-deps")
		{

			sources= "@build\\sources.list";
			classes= "@build\\classes.list";
			depends= "@build\\depends.list";
			manifest="Manifest.MF";
			output="project.jar";
			cmd1 = "javac -d . -cp "+depends+" " + sources;
			cmd2 = "md dist";
			cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
			cmd4 = "rd /Q /S com";

			peculiar::runExe(cmd1);
			peculiar::runExe(cmd2);
			peculiar::runExe(cmd3);
			peculiar::runExe(cmd4);
			
		}
		else if (option == "--run")
		{
			system("java -jar dist\\project.jar");
		}else if (option == "--md"){
			package_name = argv[2];
			package_name =  replace(package_name,".","\\");
			cmd5 = "md "+ package_name;
			peculiar::runExe(cmd5);

		}else if(option == "--cf")
		{
			package_name = argv[2];
			file_name = argv[3];
			package_name = replace(package_name,".","\\");
			
			cmd5 = "cf "+package_name+"\\"+file_name;
			peculiar::runExe(cmd5);
		}
		else{show_help();}
	}
	else{show_help();}
	return 0;
}