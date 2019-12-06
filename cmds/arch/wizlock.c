// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("��û��ʹ�����ָ���Ȩ����\n");
		
	if( !arg || arg=="" ) {
	        printf("��ǰ�ĵ�¼��������Ϊ %s ��\n",SECURITY_D->wizlevel(LOGIN_D->get_wizlock()));
		return 1;
	}
        
	if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
	
	seteuid(getuid());
	
	if( LOGIN_D->set_wizlock(lvl) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("����Ȩ���趨ʧ�ܡ�\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ: wizlock <��ʦ�ȼ�>
 
����ĳ���ȼ����µ�ʹ���߽�����Ϸ��
������ʦ�ȼ��ֱ�Ϊ (immortal) (wizard) (arch) (admin), ��Ҫȡ
������, ������ (player).
 
HELP
);
        return 1;
}
 
