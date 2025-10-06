#ifndef mxy_stl_loghpp
#define mxy_stl_loghpp

#include <iostream>
#include <string>



using namespace std;

class log
{
    string layout = "[%p]: %m: %v\n";//gcc风格
    string lay_note = "";
    string lay_warning = "";
    string lay_error = "";
    string lay_fatal = "";
    string lay_important = "";
    string out_string = "";
    int maxtype = 4;
    string _get_string(string _val)
    {
        if(_val == "")
        {
            return layout;
        }
        else
        {
            return _val;
        }
    }
    string _get_print(int _mode)//{"\033[1;34mnote\033[0m","\033[1;33mwarning\033[0m","\033[1;31merror\033[0m","\033[1;35mfatal\033[0m"}
    {
        switch(_mode)
        {
            case 0:return "\033[1;34mnote\033[0m";
            case 1:return "\033[1;33mwarning\033[0m";
            case 2:return "\033[1;31merror\033[0m";
            case 3:return "\033[1;35mfatal\033[0m";
        }
        return "_get_print ERROR";
    }
    void _do_layout()
    {
        string _layout[maxtype];
        
        
        _layout[0] = _get_string(lay_note);
        _layout[1] = _get_string(lay_warning);
        _layout[2] = _get_string(lay_error);
        _layout[3] = _get_string(lay_fatal);
        

        string new_layout[maxtype][1024] = "";
        int _layout_pos = 1;
        for(int _mode = 0;_mode < maxtype;_mode ++)
        {
            for(int _index = 0;_index <= layout.length();_index ++)
        {
            if(_layout[_mode][_index] == '%')
            {
                switch(_layout[_mode][_index + 1])
                {
                case 'p':new_layout[_mode][_layout_pos ++] += "\033[1m%s\033[0m";break;//_pos
                case 'm':new_layout[_mode][_layout_pos ++] +=  _get_print(_mode);break;
                case 'v':new_layout[_mode][_layout_pos ++] +=  "%s";break;//_val
                }
                _index ++;//+= 2
            }
            else
            {
                printf("%c",_layout[_index]);
            }
        }
        }
    }

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
    /// @param _mode 0:note 1:warning 2:error 3:fatal
    string set_lay(int _mode,string _lay)
    {
        switch(_mode)
        {
            case 0:lay_note = _lay;break;
            case 1:lay_warning = _lay;break;
            case 2:lay_error = _lay;break;
            case 3:lay_fatal = _lay;break;
        }
        return _lay;

        _do_layout();
    }
    /// @brief 按照对应的layout输出log
    /// @param mode 0:note 1:warning 2:error 3:fatal
    /// @param _pos 发生事件的位置(输出)
    /// @param _val 事件的内容(输出) 
    void print(int _mode,string _pos,string _val)
    {
        string _layout;
        switch(_mode)
        {
            case 0:_layout = _get_string(lay_note);break;
            case 1:_layout = _get_string(lay_warning);break;
            case 2:_layout = _get_string(lay_error);break;
            case 3:_layout = _get_string(lay_fatal);break;
        }

        
        printf("\033[0m");
        for(int _index = 0;_index <= layout.length();_index ++)
        {
            if(_layout[_index] == '%')
            {
                switch(_layout[_index + 1])
                {
                case 'p':printf("\033[1m%s\033[0m",_pos.c_str());break;
                case 'm':printf(_get_print(_mode).c_str());break;
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