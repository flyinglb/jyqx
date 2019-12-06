 /*
 * Object: ls command
 * File Path: /cmds/wizard/ls.c
 * Creater : Byp@MX 2000/12/15
 * Last Modify : Byp@MX 2001/03/20
 * Note : 
 *
 */

#include <ansi.h>

int main(object me, string arg)
{
        int i, j, w, col;
        string dir, *flist, str;
        dir = resolve_path(me->get("cmds_cwd"), arg);
        seteuid(getuid(me));
        if( file_size(dir)==-2 && dir[<1..<1] != "/" )   dir += "/";
        flist = get_dir(dir, -1);
        if( !sizeof(flist) ) {
                if (file_size(dir) == -2) return notify_fail("这个目录是空的。\n");
                else return notify_fail("没有这个文件或目录。\n");
        }
        w = 0;
        for(i=0;i<sizeof(flist);i++) {
/*
                for(j=0;j<sizeof(flist[i]);j++) {
                        write(i + ":"+ flist[i][j]+ " typeof:"+ typeof(flist[i][j]) +"\t");
                }
        }
*/
                if( flist[i][0] == "." || flist[i][0] == "..")  continue;
                if( flist[i][1] == -2 ) flist[i][0] += "/";
                if( strlen(flist[i][0])>w ) w = strlen(flist[i][0]) + 1;
        }
        col = 70/ (w+6)
        write("目录：" + dir + "\n");
        for(i=0, j=0; i<sizeof(flist); i++) {
                if(flist[i][0] == "." || flist[i][0] == ".." || flist[i][1])==-1 ) {
                        j++;continue;
                }
                str = sprintf("%4d %-*s%s", flist[i][1]/1024+1, w+1,
                                flist[i][0] + (find_object(dir + flist[i][0])? "*":" ") ,
                                ((i-j+1)%col)?"  ":"\n");
                write(str);

        }
        return 1;
}


int help(object me)
{
        write(@HELP
指令格式: ls [<路径名>]
 
列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录
的内容，所列出的档案中前面标示 * 号的是已经载入的物件。
 
范例:
'ls /' 会列出所有位於根目录下的档案及子目录.
 
HELP
        );
        return 1;
}
