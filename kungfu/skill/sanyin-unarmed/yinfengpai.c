// yinfengpai.c ������ �������ġ�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int busy_time;
    if ( (time()-me->query_temp("perform_time"))<4)
        return notify_fail("�����������Ѿ���ɢ���ˣ������޷������ˡ�\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("������˭��\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if((int)me->query_str() < 25)
        return notify_fail("���������,�޷��Ļ�!\n");
    if((int)me->query_skill("xuantian-force",1) < 100 )
        return 
        notify_fail("���ڹ���Ϊ����������ʹ��������!\n");
 if((int)me->query_skill("unarmed") < 120 || me->query_skill("sanyin-unarmed",1) < 100 )
        return 
        notify_fail("���ȭ����Ϊ����,Ŀǰ������ʹ�������ľ���!\n");
    if((int)me->query("neili") < 400)
        return notify_fail("�����������, ����ʹ��������! \n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�������\n");

    message("vision", HIB "��о����ܵĿ�����Ȼ���䣡\n\n" NOR, environment(me), ({me}) );
    tell_object(me, HIB "��ʹ�������ľ��У������ھ���һ�ɺ���Ϯ��"+target->name()+"������\n\n" NOR);

    if( random(me->query_skill("unarmed")) > (int)target->query_skill("parry") / 3 )
    {
        tell_object(target, HIB "��ͻȻ�����ȫ������һ�㣬�������ã�\n" NOR);
        message("vision", HIB "ֻ��"+target->name()+"ͻȻ����ɫ�����ߣ��������ã�\n\n" NOR, environment(me), ({target}) );
        busy_time=random( (int)me->query_skill("sanyin-unarmed",1) / 20 )+1;
        target->start_busy( busy_time );
        me->add("neili", -100);
    }
    else
    {
    message("vision", HIB + target->name() + "ͻȻ����һ�ɺ���ӭ������������ϸ�������������\n" NOR,environment(me),({target}));
    tell_object(target, HIB "��ͻȻ������һ�ɺ���ӭ������������ϸ�������������\n" NOR);
    message_vision(HIB "$n����ϸ��ԭ����$N�ڰ��Է�����ŭ���������������Ҳ�����ң����У�\n" NOR,me,target);
    target->fight_ob(me);
    me->fight_ob(target);
    me->start_busy(3);
    }
    me->set_temp("perform_time",time());
    return 1;
}

