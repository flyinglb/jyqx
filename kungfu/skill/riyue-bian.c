// riyue-bian.c ���±޷�
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N����������һ�С�"+RED+"��ʯʽ"+NOR+"��������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
    "lvl" : 0,
    "skill_name" : RED "��ʯʽ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N����һת��һ�С�"+RED+"�ϴ�ʽ"+NOR+"��������$w��������ڿ�һ���͵���$n��ͷ����",
    "lvl" : 36,
    "skill_name" : RED "�ϴ�ʽ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+HIW+"����ʽ"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 89,
    "skill_name" : HIW "����ʽ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+HIW+"�ֺ�ʽ"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 112,
    "skill_name" : HIW "�ֺ�ʽ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+BLU+"�ѿ�ʽ"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 135,
    "skill_name" : BLU "�ѿ�ʽ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+BLU+"�������"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 158,
    "skill_name":  BLU "�������" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+YEL+"��շ�ħ"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 210,
    "skill_name" : YEL "��շ�ħ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+HIR+"���ޱ�"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 260,
    "skill_name" : HIR "���ޱ�" NOR,
    "damage_type":  "����"
]),
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 260;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("���������һ�����Ӳ������޷���\n");

    if( (int)me->query("max_neili") < 500 )
        return notify_fail("����������㣬û�а취�����±޷�, ����Щ���������ɡ�\n");
    if (me->query_skill("whip", 1) <=me->query_skill("riyue-bian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
    if ((int)me->query_skill("yijing-force", 1) < 50)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 50)
    if ((int)me->query_skill("buddhism-force", 1) < 50)
    if ((int)me->query_skill("taiji-shengong", 1) < 50)
        return notify_fail("�������������򲻹����޷�ѧ���±޷���\n");
    return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("riyue-bian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������±޷���\n");
    me->receive_damage("qi", 45);
    return 1;
}
string perform_action_file(string action)
{
    if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
        return __DIR__"riyue-bian/" + action;
}
