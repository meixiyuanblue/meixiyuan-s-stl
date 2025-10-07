#include <iostream>
#include <string>
#include "log\log.hpp"

#define ll long long

using namespace std;
using namespace mxy_stl_log;


int main()
{
    //cout << "\033[31m 0 \033[0m 1\n";
    cout.put('\033[31m');
    cout.put('0');
    cout.put('\033[0m');
    cout.put('1');
    /* log l;
    l.def_template("mxy","114514!!!\n");
    l.often_template(); */
    //printf("\033[0m\033[1;31m%s\033[0m", "123");
    //printf("log: list = %s",mxylist);

}
