#include <iostream>
#include "header\runner.h"

using std::cout;
using std::endl;

std::string option,sources,depends,classes,manifest,output,package_name,file_name;
std::string cmd1,cmd2,cmd3,cmd4,cmd5;

void show_help(){
	cout << "jpb <option>" << endl;
	cout << "flags: " << endl;
	cout << "--init                                   initialize project." << endl;
	cout << "--md <package>                           create a package." << endl;
	cout << "--cf <package> <source-file>             create file inside package." << endl;
	cout << "--aim                                    add attribute in manifest." << endl;
	cout << "--adeps                                  add dependencies to the project." << endl;
	cout << "--compile                                compiling to jar archive." << endl;
	cout << "--compile-deps                           compiling to jar archive with dependencies." << endl;
	cout << "--docs                                   create documentation." << endl;
	cout << "--run                                    run project." << endl;
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
void init(){
	peculiar::runExe("md build dist");
	peculiar::runExe("echo. >> build\\depends.list");
	peculiar::runExe("echo. >> Manifest.MF");
}
void compile(){
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
void compile_deps(){
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
void mdir(std::string arg2){
	package_name = arg2;
	std::string package_named = package_name;
	package_name =  replace(package_name,".","\\");
	cmd5 = "md src\\"+ package_name;
	peculiar::runExe(cmd5);
	std::cout <<"add to package.list: " +package_named <<std::endl;
	peculiar::runExe("echo "+package_named +" >> build/package.list");
}
void createfile(std::string arg2,std::string arg3){
	package_name = arg2;
	std::string package_named = package_name;
	file_name = arg3;
	package_name = replace(package_name,".","\\");
	cmd5 = "cf src\\"+package_name+"\\"+file_name;
	// adding class file config to the classes.list
	std::cout <<"add to classes.list: " +package_name <<std::endl;
	peculiar::runExe("echo "+package_name +" >> build/classes.list");
	//adding java file config to the source.list
	std::cout <<"add to sources.list: " +package_name+"\\"+file_name <<std::endl;
	peculiar::runExe("echo src\\"+package_name+"\\"+file_name +" >> build/sources.list");
	//creating java file
	peculiar::runExe(cmd5);
	//add package to the .java file
	peculiar::runExe("echo package "+package_named+"; > src\\"+package_name+"\\"+file_name );
}


void addInManifest(std::string attr, std::string value){
	peculiar::runExe("echo "+attr+": "+value+" >> Manifest.MF");
}
void addDeps(std::string deps){
	peculiar::runExe("echo "+deps+"; >> build/depends.list");
}
void docs(){
	peculiar::runExe("javadoc -d doc -sourcepath src @build\\package.list");
	peculiar::runExe("wr doc\\index.html");
}
void run(){
	system("java -jar dist\\project.jar");
}
int main(int argc, char const *argv[])
{
	if(argv[1] != NULL)
	{
		option = argv[1];
		if(option == "--init")
		{ 
			init();
		}
		else if (option == "--compile")
		{
			compile();
		}
		else if (option == "--compile-deps")
		{
			compile_deps();
		}
		else if (option == "--run")
		{
			run();
		}
		else if (option == "--md")
		{
			mdir(argv[2]);
		}
		else if(option == "--cf")
		{
			createfile(argv[2],argv[3]);
		}
		else if(option == "--adeps"){
			addDeps(argv[2]);
		}
		else if(option == "--aim")
		{
			addInManifest(argv[2],argv[3]);
		}
		else if(option == "--docs")
		{
			docs();
		}
		else
			{show_help();}
	}
	else{show_help();}
	return 0;
}