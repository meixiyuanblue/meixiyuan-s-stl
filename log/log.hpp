#ifndef mxy_stl_loghpp_all
#define mxy_stl_loghpp_all


/* 这个文件是mxy_stl的log库的总管
它会管理log库的数据
也会调用log库的其他文件

你应该在main.cpp中调用这个文件
这样才能完整启动log库


                                       重点!!!
你 **不能** 在格式字符串中添加除`p及`v以外的"`"符号
格式字符串在第一个`p及`v处插入信息

log::log(); (构造函数)会在全局中开启std::ios::sync_with_stdio(false);与std::cout.tie(nullptr);(加速cout)
这是print函数必要的, 如果你不同意, 可定义#define dont_fast_cout来阻止(log运行会变慢)


实例:
main.cpp
log(文件夹)
  log.hpp
  log*.hpp(如laoV1.2.hpp)

  
  在main.cpp中:
  #include "log/log.hpp"
  
using namespace mxy_stl_log;  //一定要加

int main()
{
  正常使用log
}
*/

/*
以下为函数表 详见文件内部
void bulid(string _name); [内部函数] 解析格式字符串

log(); 构造函数
void often_template(); 提供自带的log类型(error warning note fatal important)
void def_template(string _name, string _layout = NOLAYOUT); 创建log类型(名称, 格式字符串)


*/


#define mxylog "v1.2 on 25.10.6 on log"


#include "logV1.2.hpp" //主程序

#endif