// bx_arrow.c 碧血箭

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        string msg;
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("碧血箭只能对战斗中的对手使用。\n");
        
        if((int)me->query_skill("duji",1) < 60)
                return notify_fail("你毒技太低,无法使用这一绝技！\n");

        if((int)me->query_skill("wudu-shengong",1) < 80)
                return notify_fail("你五毒神功的功力不够，无法运用碧血箭！\n");
        
        if((int)me->query("max_neili") < 500)
                return notify_fail("你内力修为不够, 无法吐血成箭！\n");

        if((int)me->query("neili") < 200)
                return notify_fail("你内力不足, 无法吐血成箭！\n");
        /*也许不需要这判断
        if( ((int)me->query("qi")/(int)me->query("max_qi")) 
        < (int)me->query("max_qi")/10)
                return notify_fail("你气血不足, 无法吐血！\n");
        */
        msg = HIR"突然" + me->name() + "双目尽赤，对" + target->name() 
              + "怒吼道：老"+ (me->query("gender")=="女性")?"娘":"子" + "跟你拼了！\n"
              + HIW + "只见"+ me->name() + "一咬舌尖，顿时嘴里含着一口毒血，"
              + "张口就向" + target->name() + "喷了过去\n" + NOR;
        //成功条件及对手伤害
        //if() ...
        
        //自身伤害
        me->add("max_neili",random(50)+50);
        if(me->query("max_neili") < 0)
                me->set("max_neili",0);
        me->die();
        return 1;
}
