
#ifndef __RUNNER_H__
#define __RUNNER_H__
#ifdef __cplusplus


#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

extern "C"{
#endif
	namespace peculiar
	{
		void runExe(string value);
		void print(string value);
		string getExecutablePath();
	}

#ifdef __cplusplus
}
#endif
#endif 




