// blockade.c

#include <login.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
	string wiz_status, src, dst, playerid;
	object link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ���ܷ�סʱ��\n");

	seteuid(getuid());
	LOGIN_D->set_madlock(1);
        message("system", "\n*** " + RANK_D->query_rank(me) + me->short(1) + "���ڷ���ʱ��. ***\n*** ���з������е�����. �Ͽ�Ŀ����Ҫ����... ***\n", users());
        write("�����У�");

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( objectp(link_ob = ob[i]->query_temp("link_ob")) ) {
			if( (int)link_ob->save() && (int)ob[i]->save() ) {
				playerid = ob[i]->query("id");
				src = "/data/user/" + playerid[0..0] + "/" + playerid + ".o" ;
				dst = "data/keep/" + playerid ; 
				cp(src, dst);
			}
			else { 
				LOGIN_D->set_madlock(0);
				return notify_fail("ʱ�շ���ʧ���ˣ���\n");
			}
		}
	}

	write("�ɹ��ķ�ס��ʱ�ա�\n");

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: blockade
 
����ס���ڵ�ʱ�ա�����������
 
HELP
);
        return 1;
}
 
