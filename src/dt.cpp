#include <iostream>
#include "header/runner.h"

int main(int argc, char const *argv[])
{
	std::string cmd;
	cmd = "date /T && time /T";
	peculiar::runExe(cmd);
	return 0;
}

