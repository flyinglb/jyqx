// roar.c �̺�������
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me, object target)
{
    object *ob;
    int i, skill, damage;
//    if (!me->is_fighting())
//        return notify_fail("�̺�������ֻ����ս����ʹ�á�\n");
    if( (int)me->query("neili") < 100 )
        return notify_fail("�������������\n");
    skill = me->query_skill("bibo-shengong",1)+me->query_skill("force",1)/4;
    if (skill<60) return notify_fail("��ı̲��񹦻�������졣\n");
    me->add("neili", -100);
    me->receive_damage("qi", 10);
    me->start_busy(2);
    message_vision(
        HIY "$N��������˼�ȫ����������һ�����̺���������\n" NOR, me);
    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++) {
        if( !living(ob[i]) || ob[i]==me || wizardp(ob[i]) || ob[i]->query("age")<17 )
            continue;
        if( skill/2 + random(skill/2) < (int)ob[i]->query_skill("force"))
            continue;
        
        damage = skill - ((int)ob[i]->query("max_neili") / 10);
        if( damage > 0 ) {
            ob[i]->receive_damage("jing", damage * 2,me );
            if( (int)ob[i]->query("neili") < skill * 2 )
                ob[i]->receive_wound("jing", damage,me);
        tell_object(ob[i], "��ֻ������ǰһƬģ�����������ƺ�������ɽ�����������......\n");
		ob[i]->start_busy(2);
        if( !ob[i]->is_killing(me) )	ob[i]->kill_ob(me);
        if( !me->is_killing(ob[i]) )	me->fight_ob(ob[i]);
        }
    }
    return 1;
}
