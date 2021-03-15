 #include <iostream>

using std::cout;
using std::endl;
using std::string;

void show_help(){
	cout << "jarc <option>" << endl;
	cout << "option: " << endl;
	cout << "	init 			initialize project build requirement for creating jar archive." << endl;
	cout << "	mk <package> 	create package" << endl;
	cout << "	compile 		compiling to jar archive." << endl;
	cout << "	run 			run jar project." << endl;
}


string replace(string str,string ch,string name){
	size_t pos = 0;
	if(!ch.empty()){
		while((pos=str.find(ch,pos)) != string::npos){
			str.replace(pos,ch.length(),name);
			pos += name.length();
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{

	string option,sources,classes,manifest,output,package_name;
	string cmd1,cmd2,cmd3,cmd4,cmd5;

	if(argv[1] != NULL)
	{
		option = argv[1];
		if(option == "init")
		{
			system("md build dist");
			system("echo. >> build\\classes.list");
			system("echo. >> build\\sources.list");
			system("echo. >> build\\depends.list");
			system("echo. >> Manifest.MF");

		}else if (option == "compile")
		{

			sources= "@build\\sources.list";
			classes= "@build\\classes.list";
			manifest="Manifest.MF";
			output="project.jar";
			cmd1 = "javac -d . " + sources;
			cmd2 = "md dist";
			cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
			cmd4 = "rd /Q /S com";

			system(cmd1.c_str());
			system(cmd2.c_str());
			system(cmd3.c_str());
			system(cmd4.c_str());
			
		}else if (option == "run")
		{
			system("java -jar dist\\project.jar");
		}else if (option == "mk"){
			package_name = argv[2];
			package_name =  replace(package_name,".","\\");
			cmd5 = "md "+ package_name;
			system(cmd5.c_str());
			return 0;

		}
		else{show_help();}
	}
	else{show_help();}
	return 0;
}