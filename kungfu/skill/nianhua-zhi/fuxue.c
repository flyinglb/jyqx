// fuxue.c �黨ָ ���黨��Ѩ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int busy_time;
    if ( (time()-me->query_temp("perform_time"))<5)
        return notify_fail("�����������׼���ٴ�ʹ���黨��Ѩ��\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("�����˭��Ѩλ��\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    if( objectp(me->query_temp("weapon")) && objectp(me->query_temp("secondary_weapon")) )
        return notify_fail("��˫�����ű�����ε�Ѩ��\n");     

    if((int)me->query_str() < 25)
        return notify_fail("���������,����ʹ����һ����!\n");
    if((int)me->query_skill("hunyuan-yiqi",1) < 100 )
    if((int)me->query_skill("yijing-force",1) < 100 )
        return 
        notify_fail("���ڹ���Ϊ����������ʹ���黨��Ѩ!\n");
 if((int)me->query_skill("finger") < 120 || me->query_skill("nianhua-zhi",1) < 100 )
        return 
        notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!\n");
    if((int)me->query("neili") < 300)
        return notify_fail("�����������, ����ʹ���黨��Ѩ! \n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�yeah\n");

    message("vision", CYN "���ƺ�����һ���������޵ġ����͡���������\n\n" NOR, environment(me), ({me}) );
    tell_object(me, "��ʹ���黨��Ѩ���У�����������ָ�����һ�ɾ���ֱ��"+target->name()+"��ҪѨ��\n\n" NOR);

//    if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
         if( random(me->query_skill("finger")) > (int)target->query_skill("force") * 3 / 5 )

    {
        tell_object(target, HIW "��ͻȻ����û������²���ʹ�����������ã�\n" NOR);
        message("vision", CYN "ֻ��"+target->name()+"ͻȻ����ɫ��䣬�������ã�\n\n" NOR, environment(me), ({target}) );
        busy_time=random( (int)me->query_skill("nianhua-zhi",1) / 20 )+1;
        target->start_busy( busy_time );
        me->add("neili", -100);
    }
    else
    {
    message("vision", CYN + target->name() + "����ͻȻ������һ�ɾ������Լ���ҪѨ���˹���������ϸ������һ����\n" NOR,environment(me),({target}));
    tell_object(target, CYN "�����ͻȻ������һ�ɾ������Լ���ҪѨ���˹���������ϸ������һ����\n" NOR);
    message_vision(CYN "$n�Ӿ������򿴵�ԭ����$N�ڵ��Լ���Ѩλ��������ŭ���Ұ����ң����У�\n" NOR,me,target);
    if (target->query("shen") < -100 ) target->kill_ob(me);
    else target->fight_ob(me);
    me->fight_ob(target);
    me->start_busy(3);
    }
    me->set_temp("perform_time",time());
    return 1;
}

