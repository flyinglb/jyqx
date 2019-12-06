// po.c ���ܾ�ʽ��

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost, exp;
//        mapping my_fam  = me->query("family");

        skill = me->query_skill("lonely-sword",1);
        jing_cost = (int)me->query("int") - 45;

//        if(my_fam["generation"] != 13)
//        if(my_fam["master_id"] != "feng qingyang")
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�á��ܾ�ʽ����\n");

        if( me->is_fighting() )
           return notify_fail("���ܾ�ʽ��������ս����������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
           return notify_fail("�������ȥ��һ�ѽ���\n");

        if( !skill || (skill < 20))
           return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");

        if( me->query("neili") < 50 )
           return notify_fail("�������������û�������������ܾ�ʽ����\n");

        if( me->query("jing") < -jing_cost )
           return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

        exp= (int)me->query("combat_exp");
        if( skill*skill*skill/10>exp )
           return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����\n");

        msg=HIG"$Nʹ�����¾Ž�֮���ܾ�ʽ����������"+weapon->name()+HIG"���������̡�\n"NOR;
        message_vision(msg, me);

        me->add("neili", -50);
        me->add("jing", jing_cost);

        if ( skill < 60)
           me->improve_skill("lonely-sword",10);
        else if (skill < 90)
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*2- 9));
        else if (skill < 140)
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*4-9));
        else if (skill < 200)
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*8-9));
        else if (skill < 320)
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*16-9));
        else if (skill < 480)
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*32-9));
        else
           me->improve_skill("lonely-sword",10+random((int)me->query_int()*64-9));

        msg = MAG"$P�ġ����¾Ž��������ˣ�\n"NOR;
        me->start_busy(1);
        message_vision(msg, me);
        return 1;
}
