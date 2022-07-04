#include "runner.h"

int main(int argc, char const *argv[]){
    if(argv[1] != NULL){
        string arg1,arg2,default_path,cmd;

        arg1 = argv[1];
        arg2 = argv[2];

        default_path = "C:/scripts/py/";
        cmd = "python "+default_path+arg1+".py"+" "+arg2;
        peculiar::runExe(cmd);
    }else{
        peculiar::print("run command (with .py extension).");
        peculiar::print("pyr <file-name>");
    }
}