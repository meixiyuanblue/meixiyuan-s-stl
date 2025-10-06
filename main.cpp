#include <iostream>
#include <string>
#include "log\log.hpp"

#define ll long long

using namespace std;
using namespace mxy_stl_log;


int main()
{
    log l;
    l.def_template("mxy","114514!!!\n");
    l.often_template();
    //printf("\033[0m\033[1;31m%s\033[0m", "123");
    //printf("log: list = %s",mxylist);

}
