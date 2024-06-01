/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
#include "runner.h"

int main(int argc, char const *argv[]){
    if(argv[1] != NULL){
        string arg1,arg2,default_path,cmd;

        arg1 = argv[1];
        arg2 = argv[2];

        default_path = "C:/jar/";
        cmd = "java -jar  "+default_path+arg1+".jar"+" "+arg2;
        peculiar::runExe(cmd);
    }else{
        peculiar::print("run command (with .jar extension).");
        peculiar::print("jr <file-name>");
    }
}