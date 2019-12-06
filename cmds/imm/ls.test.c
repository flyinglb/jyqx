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
                if (file_size(dir) == -2) return notify_fail("���Ŀ¼�ǿյġ�\n");
                else return notify_fail("û������ļ���Ŀ¼��\n");
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
        write("Ŀ¼��" + dir + "\n");
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
ָ���ʽ: ls [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
 
����:
'ls /' ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼.
 
HELP
        );
        return 1;
}
