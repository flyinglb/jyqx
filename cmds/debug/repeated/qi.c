// Filename : /cmds/std/ride.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_ride(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, env;

	if( !arg ) return notify_fail("��Ҫ��ʲô������\n");
	if( me->query_temp("is_riding") )
		return notify_fail("���Ѿ��������ˣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if( me->is_fighting() )	return notify_fail("�㻹��ս���У�û������ȥ��\n");

	// Check if a container is specified.
	env = environment(me);

	if( !objectp(obj = present(arg, env)) || !living(obj) )
			return notify_fail("����û�������������\n");
	if( !obj->query("ridable") )
		return notify_fail("���������ҲҪ��������ƨ�ɣ�\n");
	return do_ride(me, obj);
	write("����ȥ�ˡ�\n");
}
	
int do_ride(object me, object obj)
{
	object old_env, *guard;

	if( !obj ) return 0;

	if( guard = obj->query_temp("guarded") ) {
		guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() 
				+ "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
	}

	if( obj->move(me) )
	{
		message_vision( "$N����Ծ��$n�����ֺ��ǽýݡ�\n", me, obj );
		obj->set_temp("is_rided_by", me->query("id"));
		me->set_temp("is_riding", obj->query("name"));
	}
	else
	{
		message_vision( "$N���ϴ��Ķ���̫���ˣ��޷��ﵽ$n����ȥ��\n", me, obj );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ride | qi <������>
 
���ָ������������ϴ�������ѱ���Ķ��
 
HELP
    );
    return 1;
}
 
