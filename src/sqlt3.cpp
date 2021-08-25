 
// sqlite3 -header test.sqlite3 -init test.sql -batch .exit 


#include <iostream>
#include "runner.h"

int main(int argc, char const *argv[])
{
    std::string arg1,arg2,arg3,cmd;
    if(argv[1] != NULL && argv[2] !=NULL){
        arg1 = argv[1];
        arg2 = argv[2];
        cmd = "sqlite3 "+arg1+" -cmd \".read "+arg2+" \" -batch .exit";
        peculiar::runExe(cmd);
    }else{
        peculiar::print("run sqlite3 source file.");
        peculiar::print("   sqlt3 <output file> <source file>");
    } 
    return 0;
}
