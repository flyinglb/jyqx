// ls.c
// atu@sjfy
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
//        int mark_loaded;

	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) ){
		if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
		else return notify_fail("没有这个目录。\n");
	}
	i = sizeof(file);

	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] = "["+file[i][0]+"]";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 2;
	}
	write("目录：" + dir + "\n");
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
	else write("    没有任何档案。\n");
	write("\n");
	return 1;       
}

int help(object me)
{
        write(@HELP
指令格式: ls [<路径名>]
 
列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录
的内容，所列出的档案中前面标示 * 号的是已经载入的物件。
 
□例:
'ls /' 会列出所有位於根目录下的档案及子目录.
 
HELP
        );
        return 1;
}
