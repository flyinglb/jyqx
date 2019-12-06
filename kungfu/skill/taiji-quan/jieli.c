
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object me);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
//        string msg;
	if( !me->is_fighting() ) 
		return notify_fail("�۽���������ֻ����ս����ʹ�á�\n");
	if( target != me ) 
		return	notify_fail("��ֻ�ܽ��۽��������������Լ������ϡ�\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����Ҫ�������е�������\n");
//        if(me->query("family/family_name") != "�䵱��")
//           return notify_fail("�㲻���䵱�ɵĵ��ӣ�����ʹ�þ��У�\n")

	if( (int)me->query_skill("taiji-quan", 1) < 100 )
		return notify_fail("���̫��ȭ������죬����ʹ�á�������������\n");
	if( (int)me->query_skill("taiji-shengong", 1) < 100 )
		return notify_fail("���̫���񹦲�����죬����ʹ�á�������������\n");
        if( (int)me->query_int() < 60 )
		return notify_fail("��Ĳ���̫���ˣ������ˡ�������������\n");
        if( (int)me->query_dex() < 40 )
		return notify_fail("����ٶ�̫�������ʺ�ʹ�á�������������\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("tjj_jie") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("taiji-quan",1);
	message_vision(HIR "$Nʹ��̫��ȭ���ľ��裬��ס�Լ��������ҪѨ���������ƽ�Է���ʽ��\n"NOR,me);

	me->set_temp("tjj_jie", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/5);

	me->add("neili", -200);
	me->start_busy(3);

	return 1;
}

void remove_effect(object me)
{
	me->delete_temp("tjj_jie");
	tell_object(me, HIY "���[��������]������ϣ���Чʧ���ˡ�\n"NOR);
}

