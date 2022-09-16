#include "runner.h"

int main(int argc, char const *argv[]) {
  // clone current  instance of terminal.
  if (argv[1] != NULL) {
    string arg1;
    arg1 = argv[1];
    if (arg1 == "-h") {
      peculiar::print("clone current  instance of terminal.");
    } else {
      peculiar::print("clone current  instance of terminal.");
    }

  } else {
    string cmd;
    cmd = "start cmd";
    peculiar::runExe(cmd);
  }
  return 0;
}
