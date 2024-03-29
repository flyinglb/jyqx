// atu@sjfy
inherit F_CLEAN_UP;
int grep(string dir,string pat);

int main(object me,string arg)
{
        string dir,pat;

        if (!arg) return
                notify_fail("指令格式: grep <路径> <字符串> \n");

        dir = me->query("cwd");
        pat = arg;
        if (sscanf(arg, "%s %s", dir, pat)==2 )
        {
                dir = resolve_path(me->query("cwd"), dir);
        }

        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";

        printf("你想在%s中寻找%s\n",dir,pat);

        grep(dir,pat);
        return 1;
}

int grep(string dir,string pat)
{
        int i, j;
        mixed *file;
        string file2,dirstr;

        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
                else
                return notify_fail("没有这个目录。\n");
        }

        i = sizeof(file);
        if (sizeof(file))

                for(i=0, j = sizeof(file); i<j; i++) {
                                if (file[i][1] != -2)   {
                                file2 = read_file(dir+file[i][0]);
                                if (strsrch(file2,pat) != -1) write(dir+file[i][0]+"\n");
                        } 
                        else {  dirstr=dir+file[i][0]+"/";
//                              write(dirstr+"\n");
                                grep(dirstr,pat);}
                        }
        return 1;       
}

int help(object me)
{
        write(@HELP
指令格式: grep [<路径名>] [<内容>]
 
在指定目录下所有的档案搜索指定的字符串, 如果没有指定目录, 
则当前所在目录为指定目录。
 
□例:
'grep /' 搜索文档.
 
HELP
    );
    return 1;
}
