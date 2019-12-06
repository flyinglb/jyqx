// kantou.c

#include <ansi.h>
inherit F_CLEAN_UP;

int do_kan(object me, object ob, object weapon);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
//        object obj, *inv, weapon;
        object obj, weapon;

	if( !arg ) return notify_fail("��Ҫ��˭��ͷ��\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

        if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		 (string)weapon->query("skill_type") != "blade"))
		return notify_fail("�㲻�õ������￳�ö���\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("��ֻ�ܿ�ʬ���ͷ��\n");

	if(userp(obj) || living(obj) )
		return notify_fail("�ǻ��ǻ�ģ���ɱ�˲��ܿ�ͷ��\n");

	if( me->is_fighting() )	return notify_fail("�㻹��ս���У����뿳�˼ҵ�ͷ��\n");

	return do_kan(me, obj, weapon);
}
	
int do_kan(object me, object obj, object weapon)
{
	object newob;
	string newname;

	if( !obj ) return 0;
	if (obj->query("kantou") == 1)
	{
		message_vision( "$N�Ǹ���ͷʬ��\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if(strsrch(newname, "���õ�ʬ��") >= 0)
	{
		message_vision( "��ʬ������ɶ��ѽ��\n", obj );
		return 1;
	}
	if(strsrch(newname, "ʬ��") >= 0)
		newname = replace_string(newname, "ʬ��", "ͷ­");
	else
	{
		message_vision(obj->query("name")+"��ʲôͷ�ɿ��ġ�\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob ->set("name", HIR+newname+NOR);
	newob ->move(me);
	if( me->is_fighting() ) me->start_busy(1);
	message_vision( "$N����"+weapon->query("name")+"��$n���Դ�����������\n", me, obj );
	obj->set("kantou", 1);
	newname = obj->query("name");
	if(strsrch(newname, "ʬ��") >= 0)
		newname = replace_string(newname, "ʬ��", "��ͷʬ��");
	obj->set("name", newname);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : kantou <ʬ������>
 
���ָ��������㿳�µ������ߵ�ͷ­.
 
HELP
    );
    return 1;
}
 
