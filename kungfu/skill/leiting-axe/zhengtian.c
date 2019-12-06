// leiting.c by wyz
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int count,skill;
 
    if( !me->is_fighting() )
        return notify_fail("「雷霆震天」只能在战斗中使用。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "axe")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "axe")
            return notify_fail("你使用的武器不对。\n");
    if((int)me->query_dex() < 30)
        return notify_fail("你的身法不够, 目前还不能使用「雷霆震天」! \n");
    if((int)me->query_skill("dodge") < 500)
        return notify_fail("你的轻功修为不够, 不能使用「雷霆震天」！\n");
    skill=me->query_skill("leiting-axe",1);
    if( skill < 300 )
        return notify_fail("你的斧法修为不够， 目前不能使用「雷霆震天」! \n");
    
    if( (int)me->query("neili") < 5000 )
        return notify_fail("你的真气不够！\n");
    msg = HIG "$N身形巍然卓立，暴喝一声使出雷霆斧法的绝技「雷霆震天」！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    if (weapon == me->query_temp("secondary_weapon"))
        me->set_temp("secondly_weapon",1);
    for (count=0;count<5;count++){
        me->add_temp("str",skill/10);
        COMBAT_D->do_attack(me, ob, weapon, 0);   
    }
    me->delete_temp("str");
    me->delete_temp("secondly_weapon");

    me->set_temp("perform",1);
    call_out("del_perform",3,me);
    return 1;
}

void del_perform(object me)
{
   if (!me) return;
   me->delete_temp("perform");
}


