#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        HIY "$n����΢Ц����������ׯ��֮ɫ��$N���������ڵأ���Ĥ�ݡ�\n" NOR ,
});
mapping *action = ({
([      "action": MAG "$N�黨΢Ц������ӿ��һƬ��������$n" NOR ,
        "force" : 0,
        "dodge" : 0,
        "damage": 0,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type":   "ʥ��֮��"
]),
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "unarmed" || usage == "parry" 
           || usage == "blade" || usage == "whip" || usage == "force" ;
}
string query_skill_name(int level)
{
        return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        return action[0];
}
string query_dodge_msg(string limb)
{
        return dodge_msg[0];
}
int valid_learn(object me)
{   
    if ( ! wizardp(me))
        return notify_fail("�۾������£���ֻ������ʦѧϰ��\n");
}
string exert_function_file(string func)
{
    return __DIR__"king-of-dragon/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if ( ! userp (victim)) 
    if ( living (victim)) victim -> unconcious () ;
}
