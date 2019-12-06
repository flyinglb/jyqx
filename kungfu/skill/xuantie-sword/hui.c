// hui.c ������ʽ

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost, exp;
//        mapping my_fam  = me->query("family");

        skill = me->query_skill("xuantie-sword",1);
        jing_cost = (int)me->query("int") - 45;

//         if(my_fammaster_id != "yang guo)
//:           return notify_fail("�㲻������ĵ��ӣ�����ʹ�á��ܾ�ʽ����\n")

        if( me->is_fighting() )
           return notify_fail("������ʽ��������ս����������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (string)weapon->query("id") != "xuantiesword" )
                return notify_fail("�������������, ��������������ʽ����\n");

        if( !skill || (skill < 20))
           return notify_fail("������������ȼ�����, ��������������ʽ����\n");

        if( me->query("neili") < 100 )
           return notify_fail("�������������û����������������ʽ����\n");

        if( me->query("jing") < -jing_cost )
           return notify_fail("������̫���ˣ��޷����о�������������ʽ����\n");

        exp = (int)me->query("combat_exp");
        if( skill*skill*skill/10>exp )
           return notify_fail("���ʵս���鲻�����޷���ᡸ����ʽ����\n");

        msg=HIC"$Nʹ����������֮������ʽ����������"+weapon->name()+HIC"�����һӡ�\n"NOR;
        message_vision(msg, me);

        if( !environment(me)->query("valid_xuantie-sword") )
                return notify_fail("�������ȥ�ƺ�ûʲôЧ����\n");

        me->add("neili", -100);
        me->add("jing", jing_cost);
	if ( skill < 240 )
		me->improve_skill("xuantie-sword",20
			+random((int)me->query_skill("sword")*2)
			+random((int)me->query_skill("force")*2)
			+random((int)me->query_skill("parry"))
			+random((int)me->query_skill("xuantie-sword"))
			+random((int)me->query("int")*6)
			+random((int)me->query("str")*6));
	else if ( skill < 440 )
		me->improve_skill("xuantie-sword",40
			+random((int)me->query_skill("sword")*4)
			+random((int)me->query_skill("force")*4)
			+random((int)me->query_skill("parry")*2)
			+random((int)me->query_skill("xuantie-sword")*2)
			+random((int)me->query("int")*10)
			+random((int)me->query("str")*10));
	else if ( skill < 600 )
		me->improve_skill("xuantie-sword",80
			+random((int)me->query_skill("sword")*8)
			+random((int)me->query_skill("force")*8)
			+random((int)me->query_skill("parry")*4)
			+random((int)me->query_skill("xuantie-sword")*4)
			+random((int)me->query("int")*14)
			+random((int)me->query("str")*14));
	else
		me->improve_skill("xuantie-sword",120
			+random((int)me->query_skill("sword")*16)
			+random((int)me->query_skill("force")*16)
			+random((int)me->query_skill("parry")*8)
			+random((int)me->query_skill("xuantie-sword")*8)
			+random((int)me->query("int")*18)
			+random((int)me->query("str")*18));

	me->improve_skill("force", random(30) + 30 );
        msg = HIY"$P�ġ����������������ˣ�\n"NOR;
        me->start_busy(1);
        message_vision(msg, me);
        return 1;
}
