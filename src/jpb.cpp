
#include "runner.h"

string option,sources,depends,classes,manifest,output,package_name,file_name;
string cmd1,cmd2,cmd3,cmd5;

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
	// cout << "--clean                                  clean the project." << endl;
}


std::string replace(string str,string ch,string name){
	size_t pos = 0;
	if(!ch.empty()){
		while((pos=str.find(ch,pos)) != string::npos){
			str.replace(pos,ch.length(),name);
			pos += name.length();
		}
	}
	return str;
}
void init(){
	peculiar::runExe("md Jbuild dist");
	peculiar::runExe("echo. >> Jbuild\\depends.properties");
	peculiar::runExe("md src\\test");
	peculiar::runExe("cf src\\test\\Test.java");
}
void compile(){
	sources= "@Jbuild\\sources.properties";
	classes= "@Jbuild\\classes.properties";
	manifest="JMANIFEST.info";
	output="project.jar";
	cmd1 = "javac -d . " + sources;
	cmd2 = "md dist";
	cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
	peculiar::runExe(cmd1);
	peculiar::runExe(cmd2);
	peculiar::runExe(cmd3);
}
void compile_deps(){
	sources= "@Jbuild\\sources.properties";
	classes= "@Jbuild\\classes.properties";
	depends= "@Jbuild\\depends.properties";
	manifest="JMANIFEST.info";
	output="project.jar";
	cmd1 = "javac -d . -cp "+depends+" " + sources;
	cmd2 = "md dist";
	cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
	peculiar::runExe("md lib dist\\lib");
	peculiar::runExe("copy lib  dist\\lib");
	peculiar::runExe(cmd1);
	peculiar::runExe(cmd2);
	peculiar::runExe(cmd3);
}
void mdir(std::string arg2){
	package_name = arg2;
	string package_named = package_name;
	package_name =  replace(package_name,".","\\");
	cmd5 = "md src\\"+ package_name;
	peculiar::runExe(cmd5);
	cout <<"add to package.properties: " +package_named << endl;
	peculiar::runExe("echo "+package_named +" >> Jbuild/package.properties");
}
void createfile(string arg2,string arg3){
	package_name = arg2;
	string package_named = package_name;
	file_name = arg3;
	package_name = replace(package_name,".","\\");
	cmd5 = "cf src\\"+package_name+"\\"+file_name;
	// adding class file config to the classes.list
	cout <<"add to classes.properties: " +package_name <<endl;
	peculiar::runExe("echo "+package_name +" >> Jbuild/classes.properties");
	//adding java file config to the source.list
	cout <<"add to sources.properties: " +package_name+"\\"+file_name <<endl;
	peculiar::runExe("echo src\\"+package_name+"\\"+file_name +" >> Jbuild/sources.properties");
	//creating java file
	peculiar::runExe(cmd5);
	//add package to the .java file
	peculiar::runExe("echo package "+package_named+"; > src\\"+package_name+"\\"+file_name );
}


void addInManifest(string attr,string value){
	peculiar::runExe("echo "+attr+": "+value+" >> JMANIFEST.info");
}
void addDeps(string deps){
	peculiar::runExe("echo "+deps+"; >> Jbuild/depends.properties");
}
void docs(){
	peculiar::runExe("javadoc -d doc -sourcepath src @Jbuild\\package.properties");
	peculiar::runExe("wr docs\\index.html");
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
		else if(option == "--test")
		{
			peculiar::runExe("java src\\test\\Test.java");
		}
		else
			{show_help();}
	}
	else{show_help();}
	return 0;
}