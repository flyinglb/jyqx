// qiankundanuoyi.c 乾坤大挪移
// by King 97.05
inherit SKILL;
string *parry_msg = ({
    "$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
    "$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
    "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
    "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
    "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
    "$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
    "$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
    "$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});
string *dodge_msg = ({
    "$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
    "$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
    "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
    "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
    "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
    "$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
    "$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
    "$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}
string query_parry_msg(object me,object weapon)
{
       me->set_temp("fight/parry", (int)me->query_skill("qiankundanuoyi",1));
       return parry_msg[random(sizeof(parry_msg))];
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("qiankundamuoyi",1));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
    return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。\n");
}
int practice_skill(object me)
{
    return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。\n");
}
string perform_function_file(string func)
{
        return __DIR__"qiankundanuoyi/" + func;
}
