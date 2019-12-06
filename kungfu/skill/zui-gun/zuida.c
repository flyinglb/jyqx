// zuida.c ������� [�������]
#include <ansi.h>
inherit F_SSERVER;
void remove_effect(object me, int amount, int amount1);
int perform(object me, object target)
{
    object weapon;  
    string msg;
    int count, count1, cnt, skill;
    
    if( !me->is_fighting() )
        return notify_fail("���������ֻ����ս����ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
            return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query_temp("zuida") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
    if( (int)me->query_str() < 25 )
        return notify_fail("��ı���������Ŀǰ����ʹ�ô˾���! \n");
    if( (int)me->query_skill("hunyuan-yiqi", 1) < 60)
     if( (int)me->query_skill("yijing-force",1) < 60)
        return notify_fail("��Ļ�Ԫһ�����Ĺ�������������ʹ�ô��������\n");
    if( (int)me->query_skill("club") < 90)
        return notify_fail("��Ĺ�����Ϊ����������ʹ�ô������! \n");
    if( (int)me->query("neili") < 500 )
        return notify_fail("����������㣡\n");
    
    msg = HIY "$Nʹ����������ľ�����������򡹣�������Ȼ����, ����Ȼ�ӿ죡\n" NOR;
    
    message_vision(msg, me, target);
    skill = me->query_skill("zui-gun",1);
    cnt =(int)( (int)me->query_condition("drunk") / 3 );
    count = me->query_str() * random(cnt + 2);
    count1 = me->query_dex() * random(cnt + 2);
    me->add_temp("apply/attack",  count);
    me->add_temp("apply/dodge", count1);
    me->set_temp("zuida", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count, count1 :), skill /3 );
    me->add("neili", -150);
    return 1;
}
void remove_effect(object me, int amount, int amount1)
{
    
    if ( (int)me->query_temp("zuida") ) 
    {
    me->add_temp("apply/attack",  -amount);
    me->add_temp("apply/dodge", -amount1);
        me->delete_temp("zuida");
        tell_object(me, HIY "��İ�������˹���ϣ��������ջص��\n" NOR);
    }
}
int clean_up()
{
    return 1;
}
void reset()
{
}

