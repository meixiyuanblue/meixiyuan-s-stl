#ifndef mxy_stl_loghpp
#define mxy_stl_loghpp

#include <iostream>
#include <string>
#include <map>
#include <fstream>

#define NOLAYOUT "no_layout.layout=NULL.10723969-6904-485a-91bf-11f19f09006e"

//-----------------------------------------------------------------------------|
namespace mxy_stl_log
{
    using namespace std;

    class log
    {
        string layout_all = "[%p]: %v\n";                                      //默认格式字符串(g++风格)
        map<string, string> layout;                                            //格式字符串的储存空间
        map<string, int>layout_pos;                                            //格式字符串pos项的位置
        map<string, int>layout_val;                                            //格式字符串val项的位置
        int type_num = 0;                                                      //格式字符串的储存空间已用的数量
        
        //[内部函数] 解析格式字符串
        void build(string _name, string _layout)
        {
            string _new_layout = "";
            bool _flag_pos= false, _flag_val = false;                          //防止有多个标识符导致多次insert
            for(int _index = 0; _index < _layout.length(); _index ++)          //遍历格式字符串, 找出pos与val的位置
            {
                if(_layout[_index] == '`')                                     //找到标识符
                {
                    if(_layout[_index + 1] == 'p' && !_flag_pos)               //标识符为pos
                    {
                        layout_pos.insert({_name, _new_layout.size()});
                        _flag_pos = true;
                    }
                    if(_layout[_index + 1] == 'v' && !_flag_val)               //标识符为val
                    {
                        layout_val.insert({_name, _new_layout.size()});
                        _flag_val = true;
                    }
                    _index ++;                                                 //循环结束后_index会+2, 避开格式化标识符的第二位
                    continue;
                }
                else                                                           //正常字符
                {
                    _new_layout += _layout[_index];                            //链接新字符
                }
            }

            layout.insert({_name, _new_layout});                               //完成记录
        }

    public:
        //构造函数
        log()
        {
            #ifndef dont_fast_cout
            ios::sync_with_stdio(0);                                           //cout加速
            cin.tie(0);cout.tie(0);                                            //cout加速
            cout.flush();
            #endif
        }

        //提供自带的log类型(error warning note fatal important)
        void often_template()
        {
            ifstream _layout("log/often_template.txt");   
            string _temp_layout_num = "";                                      //int pair的数量
            getline(_layout, _temp_layout_num);                                //读取pair的数量
            int _often_num = stoi(_temp_layout_num);                           //转换int pair的数量为int
            for(int _index = 1; _index <= _often_num; _index ++)
            {
                string _temp_name;
                string _temp_layout = "";
                getline(_layout, _temp_name);                                  //读取pair
                getline(_layout, _temp_layout);                                //读取pair
                def_template(_temp_name, _temp_layout);                        //用pair创建log类型
            }
            return ;
        }

        
        /// @brief 创建log类型(名称, 格式字符串)
        /// @param _name 新log类型的名字(不能重名)
        /// @param _layout 格式字符串
        void def_template(string _name, string _layout = NOLAYOUT)
        {
            if(_name.empty() || _layout.empty())                               //玩不起直接销毁
            {
                abort();
            }
            if(_layout == NOLAYOUT)                                            //默认的格式字符串
            {
                _layout = layout_all;
            }
            if(layout.count(_name))                                            //已存在
            {
                return ;
            }
            build(_name, _layout);                                             //解析格式字符串
            return ;                                                           
        }

    };
}
#endif