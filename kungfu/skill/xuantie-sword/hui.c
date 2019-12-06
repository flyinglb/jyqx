// hui.c 「挥浪式

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
//:           return notify_fail("你不是杨过的弟子，不能使用「总诀式」。\n")

        if( me->is_fighting() )
           return notify_fail("「挥浪式」不能在战斗中演练。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if( (string)weapon->query("id") != "xuantiesword" )
                return notify_fail("你必须拿玄铁剑, 才能演练「挥浪式」！\n");

        if( !skill || (skill < 20))
           return notify_fail("你的玄铁剑法等级不够, 不能演练「挥浪式」！\n");

        if( me->query("neili") < 100 )
           return notify_fail("你的内力不够，没有力气演练「挥浪式」！\n");

        if( me->query("jing") < -jing_cost )
           return notify_fail("你现在太累了，无法集中精神演练「挥浪式」！\n");

        exp = (int)me->query("combat_exp");
        if( skill*skill*skill/10>exp )
           return notify_fail("你的实战经验不够，无法体会「挥浪式」！\n");

        msg=HIC"$N使出玄铁剑法之「挥浪式」，将手中"+weapon->name()+HIC"左右乱挥。\n"NOR;
        message_vision(msg, me);

        if( !environment(me)->query("valid_xuantie-sword") )
                return notify_fail("你挥来挥去似乎没什么效果。\n");

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
        msg = HIY"$P的「玄铁剑法」进步了！\n"NOR;
        me->start_busy(1);
        message_vision(msg, me);
        return 1;
}
