// ls.c
// atu@sjfy
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) ){
		if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
		else return notify_fail("û�����Ŀ¼��\n");
	}
	i = sizeof(file);

	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] = "["+file[i][0]+"]";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 2;
	}
	write("Ŀ¼��" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
		{
			int mode=0;     // unloaded file
			if (strsrch(file[i][0], "]") >= 0) mode = 1; // dir
			else if (find_object(dir+file[i][0])) mode =2; // loaded file

			printf("%4dK %-*s%s",
				file[i][1]/1024 + 1,
				w+(mode==2? 12: 17),
				(mode==1? WHT: mode==2? "": YEL) +file[i][0] + (mode==2? "*": " ") + NOR,
				((i+1)%col)?"  ":"\n");
		}
	else write("    û���κε�����\n");
	write("\n");
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
