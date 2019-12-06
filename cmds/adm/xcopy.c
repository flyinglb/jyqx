// xcopy.c 复制文件和目录
// create by byp@jyqxz 2000/09/16

inherit F_CLEAN_UP;
#include <ansi.h>

string dir_info(string dir_path, string wildcard_str, int flag_dir, int flag_sub, int flag_lon);
string sub_dir_info(string sub_dir_path, string wildcard_str, int flag, int flag_lon);
string filter_arg(string cwd, string filt_path, int flag);

int do_match(string str, string substr);
int files_cont, dirs_cont, sub_dirs_cont, sub_files_cont;

int main(object me, string arg)
{
        string temp_path, src_path, dst_path, w_str,  str;
        int flag_yes, flag_sub, flag_lon;
        files_cont = 0; dirs_cont = 0;
        
        if(!arg || arg == " ") 
                return notify_fail("指令格式 : xcopy <原文件名> <目标文件名> [-s] [-y] [-f]\n");

        if(sscanf(arg, "%s %s -%s", temp_path, dst_path, str) == 3) {//分解参数
                if(strsrch(str,"y") != -1) flag_yes = 1;
                if(strsrch(str,"f") != -1) flag_lon = 1;
                if(strsrch(str,"s") != -1) flag_sub = 1;
                src_path = filter_arg(me->query("cwd"), temp_path, 0);
                w_str = filter_arg(me->query("cwd"), temp_path, 1);
        } else if(sscanf(arg, "%s %s", temp_path, dst_path) != 2) {
               return notify_fail("指令格式 : xcopy <原文件名> <目标文件名> [-s] [-y] [-f]\n"); 
        } else {
                src_path = filter_arg(me->query("cwd"), temp_path, 0);
                w_str = filter_arg(me->query("cwd"), temp_path, 1);
        }
        write("debug message: "+src_path+" "+w_str+" y:"+flag_yes+" s:"+flag_sub+" f:"+flag_lon+"\n");
        if(file_size(src_path) == -1) 
                return notify_fail("错误：无效文件名或目录 \n");
        if( !nullp(w_str) && (query_wiz_level("(admin)")>wiz_level(me)) )//不是 admin 不允许使用通配符
                return notify_fail("错误：无效文件名或目录 \n");
        
        return 1;
}

string sub_dir(string dir_path, string wildcard_str, int flag)
{
        string str;
        return str;
}

string filter_arg(string cwd, string filt_path, int flag)
{
        string *temp, new_path;
        int i, j, k, wildcard;
        
        if(flag) {//保证 filt_path 为空值
                if(nullp(filt_path)) return filt_path;
                if(filt_path == "") return new_path;
                if((strsrch(filt_path,"*")==-1) && (strsrch(filt_path,"?")==-1)) return new_path;
        }
        temp = explode(filt_path,"/");
        for(i=0;i<sizeof(temp);i++) {
                if( (strsrch(temp[i],"*")== -1)&&(strsrch(temp[i],"?")== -1) ) continue;
                wildcard = 1;
                new_path = "";
                if(flag) {
                        for(k=sizeof(temp);i<k;i++) new_path += temp[i]+"/"; 
                        new_path = new_path[0..strlen(new_path)-2];
                        return new_path;
                }
                for(j=0;j<i;j++) new_path += temp[j]+"/"; 
                break;
        }
        if(!wildcard) new_path = filt_path;
        new_path = resolve_path(cwd, new_path);
        i = strlen(new_path)-1;
        if( (new_path != "/")&&(new_path[i..i] != "/") ) new_path += "/";//确保目录结尾有 '/'
        return new_path;
}

int do_match(string str, string substr)
{
        int i;

        for(i = 0;i < sizeof(substr);i++) {
                if(i >= sizeof(str) )   return 0;
                if(substr[i..i] == "?") continue;
                if(substr[i..i] == "*") {//还需要加强
                        if((substr[i-1..i-1] == "?")&&(str[i-1..i-1] != substr[i-1..i-1])) return 1;
                        if((substr[i-1..i-1] != "?")&&(str[i-1..i-1] == substr[i-1..i-1])) return 1;
                }
                if(str[i] != substr[i]) return 0;
        }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : xcopy <原文件名> <目标文件名> [-s] [-y] [-f]
 
这个命令可以拷贝文件和目录。加 -s 参数为包括子目录
如果使用了 -f 参数则显示完整的文件或目录信息
加 -y 参数为不确认覆盖文件和目录(慎用！)。

支持通配符 '*' '?'

HELP
    );
        return 1;
}
 
