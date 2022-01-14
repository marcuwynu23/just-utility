
#include <mutex>
#include <thread>
#include <windows.h>
#include <shlwapi.h>
#include "runner.h"



void  peculiar::runExe(string value)
{
	std::mutex m;
	std::thread t{[&]
		{
			std::lock_guard<std::mutex> lock{m};
			system(value.c_str());
		}
	};
	t.join();
}
void peculiar::print(string value){
	std::mutex m;
	std::thread t{[&]
		{
			std::lock_guard<std::mutex> lock{m};
			cout << value << endl;
		}
	};
	t.join();
}


string peculiar::getExecutablePath(){
	char path[100000];
	HMODULE hModule = GetModuleHandle(NULL);
	GetModuleFileName(hModule,path,(sizeof(path)));
	PathRemoveFileSpec(path);

	return string(path);
}
