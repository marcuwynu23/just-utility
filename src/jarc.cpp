 #include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	if(argv[1] != NULL){
		string option = argv[1];
		if(option == "init"){
			system("md build dist");
			system("cf build\\classes.list");
			system("cf build\\sources.list");
			system("cf Manifest.MF");

		}else if (option == "compile"){
			string sources= "@build\\sources.list";
			string classes= "@build\\classes.list";
			string manifest="Manifest.MF";
			string output="project.jar";

			string cmd1 = "javac -d . " + sources;
			string cmd2 = "md dist";
			string cmd3 = "jar -cvfm dist\\"+output+" "+manifest+" "+classes;
			string cmd4 = "rd /Q /S com";

			system(cmd1.c_str());
			system(cmd2.c_str());
			system(cmd3.c_str());
			system(cmd4.c_str());
		}else if (option == "run"){
			system("java -jar dist\\project.jar");
		}else{
			cout << "jarc <option>" << endl;
			cout << "option: " << endl;
			cout << "	init 		initialize project build requirement for creating jar archive." << endl;
			cout << "	compile 	compiling to jar archive." << endl;
			cout << "	run 		run jar project." << endl;
		}
	}else{
		cout << "jarc <option>" << endl;
		cout << "option: " << endl;
		cout << "	init 		initialize project build requirement for creating jar archive." << endl;
		cout << "	compile 	compiling to jar archive." << endl;
		cout << "	run 		run jar project." << endl;
	}
	return 0;
}