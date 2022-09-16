// chrome --auto-open-devtools-for-tabs
#include "runner.h"

int main(int argc, char const *argv[]) {
  if (argv[1] != NULL) {
    string v, cmd;
    v = argv[1];
    cmd = "chrome --auto-open-devtools-for-tabs " + v;
    peculiar::runExe(cmd);
  } else {
    peculiar::print("run chrome with	devtools");
    peculiar::print("chrome-dev < url >");
  }
  return 0;
}
