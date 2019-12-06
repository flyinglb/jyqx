// vote command..
// Modified by Marz, 04/18/96

#include <net/dns.h>
#include <ansi.h>

inherit F_CLEAN_UP;

// int valid_voters(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;
        
	if (((int)me->query("age")<16) && !wizardp(me))
		return notify_fail("�������Ƕ�Ϸ��С����һ����ȥ��\n");

	if ((int)me->query("xkx_jail"))
		return notify_fail("�㻹������ʵʵ��������˵�ɣ�\n");

	if ((int)me->query("vote/deprived"))
		return notify_fail("�����𵱳���Ū������������ͶƱȨ���£�׷��Ī����\n");

        if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2)
		return notify_fail("����ʥ��һƱ��Ҫ������˲���Ͷ��\n");
    
/**
	if (victim_name == "rumor"||victim_name == "chat")
		victim = 0; 
	else {
		victim = LOGIN_D->find_body(victim_name);
		if (!victim) return notify_fail("��ҪͶ˭��Ʊ��\n");
	}	
**/	
	victim = LOGIN_D->find_body(victim_name);
	if (!victim) return notify_fail("��ҪͶ˭��Ʊ��\n");
	if (wizardp(victim)) return notify_fail("��ҪͶ��ʦ��Ʊ��\n");
		
	if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
		|| file_size(file + ".c") <= 0 )
			return 	notify_fail("��ҪͶƱ��ʲô��\n");
	
	if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
	if ((int)file_ob->vote(me, victim) <= 0) {
		if ((int)me->query("vote/abuse")> 50) {
			write( HIG "����Ϊ����ͶƱ��ͶƱȨ�������ˣ�\n" NOR);

//			me->set("xkx_jail", 1);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
// 			me->move("/d/city/jail");
		}	
		return 0;
	}
	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0;
	int j;

        list = users();
        j = sizeof(list);
        while( j-- ) {
		// Skip those users in login limbo.
                if( !environment(list[j]) ) continue;
                if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		
		d++;
	}
	
	return d;
}


int help(object me)
{
write(@HELP
ָ���ʽ : vote <����> <ĳ��> 

�����������ĳ�˲�ȡ�ж����ɴ��ͶƱ��������������������û���˸��飬
ͶƱ���Զ�ȡ������ǰ����������<����>��

chblk:   �ر�ĳ�˽�̸Ƶ��������Ʊ���ϵ�����֮һ��ͬ�⡣
unchblk: ��ĳ�˽�̸Ƶ��������Ʊ���ϵ��ķ�֮һƱ��ͬ�⡣

HELP
    );
    return 1;
}

/**
future motion (not implemented yet):
eject: ����ĳ�ˣ�����Ʊ���ϵļ򵥶���ͬ�⡣
robot: ����ĳ���ǻ����ˣ���������˸��飬����ϵͳ��ѵ�������ߡ�
jail: ��ĳ���ͽ�����������Ʊ���ϵļ򵥶���ͬ�⡣
**/
