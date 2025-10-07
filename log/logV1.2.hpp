#ifndef mxy_stl_loghpp
#define mxy_stl_loghpp

#include <iostream>
#include <string>
#include <map>

#define NOLAYOUT "no_layout.layout=NULL.10723969-6904-485a-91bf-11f19f09006e"

//-----------------------------------------------------------------------------|
namespace mxy_stl_log
{
    using namespace std;

    class log
    {
        string layout_all = "[%p]: %v\n";                                      //默认格式字符串(g++风格)
        pair <string, string> layout[1024];                                    //格式字符串的储存空间
        int layout_pos[1024];                                                  //格式字符串pos项的位置
        int layout_val[1024];                                                  //格式字符串val项的位置
        int type_num = 0;                                                      //格式字符串的储存空间已用的数量
        
        //[内部函数] 解析格式字符串
        void build(string _name)
        {
            
        }

    public:
        //提供自带的log类型(error warning note fatal important)
        void often_template()
        {
            FILE *_often_layout;
            _often_layout = fopen("log/often_template.txt","r");               //位于同级目录
            int _often_layout_num;                                             //int pair的数量
            fscanf(_often_layout,"%d",&_often_layout_num);                     //读取pair的数量
            for(int _index = 1; _index <= _often_layout_num; _index ++)
            {
                char _temp_key[1024], _temp_val[1024];
                fscanf(_often_layout,"%s %s",_temp_key, _temp_val);            //读取pair
                string _temp_name(_temp_key);                                  //转换pair
                string _temp_layout(_temp_val);                                //转换pair
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
            layout[++ type_num] = make_pair(_name, _layout);                   //完成记录
            build(_name);       
            return ;                                                           //解析格式字符串
        }

    };
}
#endif