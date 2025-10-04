#include <iostream>
#include <string>
#include "log\log.hpp"

#define ll long long

using namespace std;



int main()
{
    log l;
    l.set_lay("[%p]: %m: %v\n");
    l.print(0,"main","note");
    l.print(1,"main","warning");
    l.print(2,"main","error");
    l.print(3,"main","falat");
    //printf("\033[0m\033[1;31m%s\033[0m", "123");
    //printf("log: list = %s",mxylist);

}
