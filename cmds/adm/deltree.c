// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
        
        if (!file) return notify_fail("你要删除那个档案?\n");
	
	file = resolve_path(me->query("cwd"), file);
	
	if( rm(resolve_path(me->query("cwd"), file)) ) {
	        log_file("edit/"+geteuid(me), sprintf("rm %s %s\n", file, ctime(time())) );
		write("Ok.\n");
	} else
		write("删除错误：无效的文件名。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你(你)删除有权修改的档案。
HELP
    );
    return 1;
}
