// anying.c
inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
     "$n一个「"+HIW+"月上柳梢头"+NOR+"」，随着$N的攻势飘起，从容躲过这一招。\n",
     "$n使出一招「"+HIR+"大漠孤烟直"+NOR+"」，猛然纵起丈余，结果$N扑了个空。\n",
    "$n身形一摇，幻出几个人影，一招「"+HIY+"碎影舞斜阳"+NOR+"」躲过了$N的攻势。\n",
    "$n一招「"+HIG+"燕子三抄水"+NOR+"」纵身跃起，倏忽已落至$N身后。\n",
    "$n左一摇，右一晃，一招「"+HIC+"云深不知处"+NOR+"」已轻松闪过。\n",
     "$n双足一点，斜斜飞起，使出「"+MAG+"斜日杏花飞"+NOR+"」已闪到$N身侧。\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}
int practice_level(){   return 60;  }
int valid_learn(object me) { 
    if (me->query_skill("dodge",1)<=me->query_skill("anying-fuxiang",1))
        return notify_fail("你的基本轻功基础不够，无法领会更高深的技巧。\n");
    else
        return 1;
    
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("你的体力太差了，不能练暗影浮香。\n");
        if (me->query_skill("yan-shuangfei", 1) < 30)
            me->receive_damage("qi", 10);
        me->receive_damage("qi", 20);
        return 1;
}
