#ifndef mxy_stl_loghpp
#define mxy_stl_loghpp

#include <iostream>
#include <string>

#define mxylog "v1.0 on 25.10.3"

using namespace std;

class log
{
    string layout = "";
    string lay_note = "";
    string lay_warning = "";
    string lay_error = "";
    string lay_fatal = "";
    string lay_important = "";

public:
    
    /**
     * @brief 设置输出格式(all)
     * @param _lay 格式化字符串  
     * 
     * `%p`=pos, `%m`=mode, `%v`=val.
    */ 
    string set_lay(string _lay)
    {
        layout = _lay;
        return layout;
    }

    //----------------------------------------------------------------------------------------
    string set_note(string _lay)
    {
        lay_note = _lay;
        return lay_note;
    }
    void note(string _pos,string _val)
    {
        string _layout;
        if(lay_note == "")
        {
            _layout = layout;
        }
        else
        {
            _layout = lay_note;
        }

        printf("\033[0m");
        for(int _index = 0;_index <= layout.length();_index ++)
        {
            if(_layout[_index] == '%')
            {
                switch(_layout[_index + 1])
                {
                case 'p':printf("\033[1m%s\033[0m",_pos.c_str());break;
                case 'm':printf("\033[1;34mnote\033[0m");break;
                case 'v':printf("%s",_val.c_str());break;
                }
                _index ++;//+= 2
            }
            else
            {
                printf("%c",_layout[_index]);
            }
        }
        printf("\033[0m");
    }

    //----------------------------------------------------------------------------------------
    string set_warning(string _lay)
    {
        lay_warning = _lay;
        return lay_warning;
    }
    void warning(string _pos,string _val)
    {
        string _layout;
        if(lay_warning == "")
        {
            _layout = layout;
        }
        else
        {
            _layout = lay_warning;
        }

        printf("\033[0m");
        for(int _index = 0;_index <= layout.length();_index ++)
        {
            if(_layout[_index] == '%')
            {
                switch(_layout[_index + 1])
                {
                case 'p':printf("\033[1m%s\033[0m",_pos.c_str());break;
                case 'm':printf("\033[1;33mwarning\033[0m");break;
                case 'v':printf("%s",_val.c_str());break;
                }
                _index ++;//+= 2
            }
            else
            {
                printf("%c",_layout[_index]);
            }
        }
        printf("\033[0m");
    }

    //----------------------------------------------------------------------------------------
    string set_error(string _lay)
    {
        lay_error = _lay;
        return lay_error;
    }
    void error(string _pos,string _val)
    {
        string _layout;
        if(lay_error == "")
        {
            _layout = layout;
        }
        else
        {
            _layout = lay_error;
        }

        printf("\033[0m");
        for(int _index = 0;_index <= layout.length();_index ++)
        {
            if(_layout[_index] == '%')
            {
                switch(_layout[_index + 1])
                {
                case 'p':printf("\033[1m%s\033[0m",_pos.c_str());break;
                case 'm':printf("\033[1;31merror\033[0m");break;
                case 'v':printf("%s",_val.c_str());break;
                }
                _index ++;//+= 2
            }
            else
            {
                printf("%c",_layout[_index]);
            }
        }
        printf("\033[0m");
    }
};

#endif

//(b)pos: (c)err/note: val