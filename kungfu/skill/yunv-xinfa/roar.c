// roar.c ��Ȼ������

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if( (int)me->query("neili") < 150 )
                return notify_fail("�㳤̾һ�����������һ����\n");


        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 10);

        me->start_busy(3);
        message_vision(
        MAG "$N���ָ��أ�����������һ������Ȼ���꡹��\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;

                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
                        continue;

                if( !ob[i]->is_killing(me) )
                        ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) )
                        me->fight_ob(ob[i]);

                damage = skill - ((int)ob[i]->query("max_neili") / 11);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "���Ȼ����һ�����������������������Ư�Ʋ�����\n");
                }
        }

        return 1;
}

