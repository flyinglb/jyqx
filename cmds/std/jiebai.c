// jiebai.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if(me->query("age") < 15)
		return notify_fail("С����һ�����ȥ��\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("�����˭��ݣ�\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( !userp(obj) )
		return notify_fail("��ֻ�ܺ���Ұݰ��ӡ�\n");

	if( !living(obj) )
		return notify_fail("��...�㻹���Ȱ�"+obj->name()+"Ū�Ѱɡ�\n");

	if (me->query("jiebai") && strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
		return notify_fail("���Ѿ����˼ҽ�ݹ��ˡ�\n");

	if(obj==me)
		return notify_fail("�㲻�ܺ��Լ���ݡ�\n");

	if( userp(obj) && (object)obj->query_temp("pending/jiebai")!=me ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "����"
			+ RANK_D->query_respect(obj) + "�����Ѿã�Ը�˴������빲���ε����գ�\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/jiebai")) )
			tell_object(old_target, RED + me->name() + "ȡ���˺����ݵ���ͷ��\n" NOR);
		me->set_temp("pending/jiebai", obj);
		tell_object(obj, YEL "�����Ը��ͶԷ���Ϊ���Թ��⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� jiebai ָ�\n" NOR);
		write(RED "�Է�����ͬ����ܽ�ݡ�����Űɡ�\n" NOR);
		return 1;
	}

	message_vision("\n$N����$n����˵��������ͬ��ͬ��ͬ��������Ըͬ��ͬ��ͬ������\n\n", me, obj);
	me->delete_temp("pending/jiebai");
	if(!me->query("jiebai"))
		me->set("jiebai", obj->query("id")+">");
	else
		me->set("jiebai", me->query("jiebai")+obj->query("id")+">");

	if(!obj->query("jiebai"))
		obj->set("jiebai", me->query("id")+">");
	else
		obj->set("jiebai", obj->query("jiebai")+me->query("id")+">");
	return 1;
}
 
int help(object me)
{
write(@HELP
ָ���ʽ : jiebai <ĳ��>
 
���ָ�������ͱ��˵Ľ�ݣ���Ȼ�Է�����Ҳͬ�⡣

HELP
    );
    return 1;
}
