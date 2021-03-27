#include <iostream>
#include <mutex>
#include <thread>


namespace peculiar
{
	void  runExe(std::string value)
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
	void print(std::string value){
		std::mutex m;
		std::thread t{[&]
			{
				std::lock_guard<std::mutex> lock{m};
				std::cout << value << std::endl;
			}
		};
		t.join();
	}

}




