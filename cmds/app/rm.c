// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
        
        if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	
	file = resolve_path(me->query("cwd"), file);
	
	if( rm(resolve_path(me->query("cwd"), file)) ) {
	        log_file("edit/"+geteuid(me), sprintf("rm %s %s\n", file, ctime(time())) );
		write("Ok.\n");
	} else
		write("ɾ��������Ч���ļ�����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : rm <����>

��ָ�������(��)ɾ����Ȩ�޸ĵĵ�����
HELP
    );
    return 1;
}
