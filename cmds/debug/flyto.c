//flyto
//by wind

#include <ansi.h>
inherit F_CLEAN_UP;

mapping xinfa_types=([
"taoism":         "道学心法",
"buddhism":       "禅宗心法",
"yunlong-xinfa":  "云龙心法",
"shenlong-xinfa": "神龙心法",
"kuihua-xinfa":   "葵花心法",
"mizong-xinfa":   "密宗心法",
"yunv-xinfa":     "玉女心法",
]);


int main(object me, string arg)
{
	object obj;
	string msg;
        string *skill;
        int i,canfly;

	if( !arg ) return notify_fail("你要去谁那里？\n");

	if (me->is_ghost())
		return notify_fail("你哪儿也飞不了！\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能起飞！\n");
	if( me->query("sleeped"))
		return notify_fail("你在睡梦中飞啊飞！\n");

        if(me->query("jing")<15)
	return notify_fail("你现在的精不够运用心法神通。\n");        
        if(me->query("qi")<15)
	return notify_fail("你现在的气不够运用心法神通。\n");        
        if(me->query("neili")<15)
	return notify_fail("你现在的内力不够运用心法神通。\n");        
        if(me->query("jingli")<50)
	return notify_fail("你现在的精力不够运用心法神通。\n");        


	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)||!living(obj)) 
	return notify_fail("没有这个玩家或生物。\n");
        if(environment(me)->query("no_fly"))
	return notify_fail("这里难以应用心法神通。\n");        
        if(obj->query("biwu"))
	return notify_fail("你不能飞往武场。\n");        

        canfly=0;
        skill = keys(xinfa_types);
        for (i=0; i<sizeof(skill); i++) {
                if( !me->query_skill(skill[i],1)||!obj->query_skill(skill[i],1)) continue;
                if(random(me->query_skill(skill[i],1))>obj->query_skill(skill[i])/2) {
                           canfly=1;
                           break;
                }
        }
        if(i==7) { 
                me->receive_damage("jing",15);
                me->receive_damage("qi",15);
                me->set("neili",me->query("neili")-15); 
                me->set("jingli",me->query("jingli")-50); 
                return notify_fail("你们之间无可通之心法。\n");                
        }
        message_vision(HIY "$N运起"+xinfa_types[skill[i]]+"之心法神通,试图飞往"+obj->query("name")+".\n" NOR, me);
        if(userp(obj)) 
                message_vision(HIY ""+me->query("name")+"运起"+xinfa_types[skill[i]]+"之心法神通,正试图飞往你处。\n" NOR, obj);
        if(canfly&&random(10)>3) {
	        message_vision(HIY "只见一阵金光闪过，$N的身影已经不见了。\n" NOR, me);
	        me->move(environment(obj));
	        message_vision(HIY "只见一阵金光闪过,$N的身影突然出现在眼前。\n" NOR, me);
        }
        else message_vision(HIR "只见$N脸上忽红忽紫, 不断变化, 却始终没能起飞,看来是失败了。\n" NOR, me);
        me->receive_damage("jing",15);
        me->receive_damage("qi",15);
        me->set("neili",me->query("neili")-15); 
        me->set("jingli",me->query("jingli")-50); 
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : flyto <目标>
 
这个指令用来使有相同心法的人之前可以互相传送. 目标可以是一个活着的玩家或npc.
传送是否成功取决于两人是否有可通之心法、心法强弱及一些其它因素.如果目标npc
不可及，会自动飞回原地。
HELP
    );
    return 1;
}



