// dir.c (ls)
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
        string temp_path, dir_path, wildcard_str, str;
        int flag_pag, flag_dir, flag_sub, flag_lon;

        files_cont = 0; dirs_cont = 0;
        
        if(!arg || arg == " ") {
                dir_path = me->query("cwd");
        } else {//命令分解写的太差
                if(arg == "/") dir_path = "/";
                else{
                        if(sscanf(arg, "-%s", str)) {//分解参数
                                temp_path = me->query("cwd");
                                if(strsrch(str,"p") != -1) flag_pag = 1;
                                if(strsrch(str,"d") != -1) flag_dir = 1;
                                if(strsrch(str,"l") != -1) flag_lon = 1;
                                if(strsrch(str,"s") != -1) flag_sub = 1;
                        } else if(sscanf(arg, "%s %s", temp_path, str) == 2) {
                                if(strsrch(str,"-p") != -1) flag_pag = 1;
                                if(strsrch(str,"-d") != -1) flag_dir = 1;
                                if(strsrch(str,"-l") != -1) flag_lon = 1;
                                if(strsrch(str,"-s") != -1) flag_sub = 1;
                } else temp_path = arg;

                        dir_path = filter_arg(me->query("cwd"), temp_path, 0);
                        wildcard_str = filter_arg(me->query("cwd"), temp_path, 1);
                }
        }
        write("debug message:"+arg+" "+flag_pag+" "+flag_dir+" "+flag_sub+" "+flag_lon+
              " "+temp_path+" "+dir_path+" "+wildcard_str+"\n");
        if(file_size(dir_path) == -1)
                return notify_fail("没有找到该文件或目录。\n");
        str = dir_info(dir_path, wildcard_str, flag_dir, flag_sub, flag_lon);
        if(!flag_pag) write(str);
        else me->start_more(str);
        
        return 1;
}

string dir_info( string dir_path, string wildcard_str, int flag_dir, int flag_sub, int flag_lon )
{
        int i, j, k , w, col, wildcard, size;
        string str;
        mixed *info;
        
        info = get_dir(dir_path,-1);
        str = "目录："+ dir_path +"\n";
        i = sizeof(info); w = 0; size = 0;

        if(nullp(wildcard_str)) wildcard = 0;
        else wildcard = 1;
        
        while(i--) {
                if( (info[i][1]==-2)&&(strlen(info[i][0])>w) )w = strlen(info[i][0]) + 1;
                if(strlen(info[i][0])>w) w = strlen(info[i][0]) + 1;
        }
         col = 70 / (w+6);
        
        if (sizeof(info))//目录
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] != -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        dirs_cont ++;
                        if(!flag_lon) {
                                str += sprintf(WHT"["NOR"%-*s"WHT"]"NOR"%4s%s",
                                       w+1,info[i][0]," ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0],WHT"   <DIR>"NOR,ftime(5,info[i][2])+"\n");
                        }
                }
       if (sizeof(info)&& !flag_dir)//文件
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] == -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        files_cont ++; size += info[i][1];
                        if(!flag_lon) {
                                str += sprintf(" %-*s %4s%s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?"*":" "),
                                       ""+(info[i][1]/1024+1), " ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?" *":" "),
                                       ""+(info[i][1]), ftime(5,info[i][2])+"\n");
                        }
                }
        str += "\n\t\t\t\t\t"WHT+files_cont+NOR" file(s)  "WHT+size+NOR
               "  bytes  \n\t\t\t\t\t "WHT+dirs_cont+NOR"  dir(s)\n";
        if(flag_sub == 1)//子目录
                for(i=0;i<sizeof(info);i++) {
                        if(info[i][1] == -1) continue;
                        if(info[i][1] != -2) continue;
                        //str += sub_dir(dir_path + info[i][0] + "/", flag_dir);
                        str += sub_dir_info(dir_path + info[i][0] + "/",wildcard_str , 1, flag_lon);//强制只显示目录名
                }
        return str += "\n";
}

string sub_dir_info(string dir_path, string wildcard_str, int flag, int flag_lon)
{
        int i, j, k, w, col, wildcard, size;
        string str;
        mixed *info;

        info = get_dir(dir_path,-1); str = "目录："+ dir_path +"\n"; 
        i = sizeof(info); w = 0; sub_dirs_cont = 0; sub_files_cont = 0; size = 0;
        
        if(nullp(wildcard_str)) wildcard = 0;
        else wildcard = 1;
        
        while(i--) {
                if (strlen(info[i][0])>w) w = strlen(info[i][0]) + 1;
        }
        col = 70 / (w+7);
        if (sizeof(info))//目录
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] != -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        sub_dirs_cont ++; 
                        if(!flag_lon) {
                                str += sprintf(WHT"["NOR"%-*s"WHT"]"NOR"%4s%s",
                                       w,info[i][0]," ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0],WHT"   <DIR>"NOR,ftime(5,info[i][2])+"\n");
                        }
                }
        if (sizeof(info)&& !flag)//文件
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] == -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        sub_files_cont ++; size += info[i][1];
                        if(!flag_lon) {
                                str += sprintf(" %-*s %4s%s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?"*":" "),
                                       ""+(info[i][1]/1024+1), " ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?" *":" "),
                                       ""+(info[i][1]), ftime(5,info[i][2])+"\n");
                        }
                }
        str += "\n\t\t\t\t\t"WHT+files_cont+NOR" file(s)  "WHT+size+NOR
               "  bytes  \n\t\t\t\t\t "WHT+dirs_cont+NOR"  dir(s)\n";
        for(i=0;i<sizeof(info);i++) {
                if(info[i][1] == -1) continue;
                if(info[i][1] != -2) continue;
                //str += sub_dir(sub_dir + info[i][0] + "/", flag);
                str += sub_dir_info(dir_path + info[i][0] + "/", wildcard_str, 1, flag_lon);//强制只显示目录名
                str += "\n";
        }
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
指令格式: dir [<路径名>] [-p] [-d] [-s] [-l]
 
列出目录下所有的子目录及档案, 如果没有指定目录, 则列出当前所在
目录的内容，所列出的档案中前面标示 * 号的是已经载入的物件。
支持通配符 '*' '?' * 代表任意字符 ? 代表一个字符

参数：
 -p(page)       分页显示
 -d(dir)        只显示目录
 -s(subdir)     包括子目录(为节省资源现只显示子目录)
 -l(long)       显示更多的信息
 
实例:
ls /            会列出所有位於根目录下的档案及子目录.
ls / -d         会列出所有位於根目录下所有目录. 
ls / -p -l      会以长信息分页显示文件或目录。

HELP
    );
    return 1;
}
