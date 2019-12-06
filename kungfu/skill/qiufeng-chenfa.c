// qiufeng-chenfa.c ������
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N����������һ�С�"+YEL+"����Ҷ"+NOR+"��������$w����һ�ɾ��磬����$n������",
    "lvl" : 0,
    "skill_name" : YEL "����Ҷ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N����һ�ӣ�һ�С�"+RED+"���Χ��"+NOR+"��������$wֱ����$n�����",
    "lvl" : 14,
    "skill_name" : RED "���Χ��" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N����һת��һ�С�"+BLK+"���ƶϴ�"+NOR+"��������$w��������ڿ�һ���͵���$n��ͷ����",
    "lvl" : 38,
    "skill_name" : BLK "���ƶϴ�" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N���᳾�ң�һ�С�"+MAG+"���绯��"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "lvl" : 60,
    "skill_name" : MAG "���绯��" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ǰһԾ��һ�С�"+GRN+"Ұ�����"+NOR+"��������$w�ֻ�$n����",
    "lvl" : 82,
    "skill_name" : GRN "Ұ�����" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ǰ��һ�С�"+HIR+"��Ӱɨ��"+NOR+"��������$w��������$nǰ��",
    "lvl" : 114,
    "skill_name" : HIR "��Ӱɨ��" NOR,
    "damage_type":  "����"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 120;  }
int valid_learn(object me)
{
    object weapon;
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("����������㣬û�а취����糾��, ����Щ���������ɡ�\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("��Ļ����������̫ǳ��\n");
    if ( !objectp(weapon = me->query_temp("weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("���������һ������������������\n");
    if (me->query_skill("whip", 1) <=me->query_skill("qiufeng-chenfa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    level   = (int) me->query_skill("qiufeng-chenfa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
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
        return notify_fail("���������������糾����\n");
    me->receive_damage("qi", 35);
    return 1;
}
string perform_action_file(string action)
{
    if ( this_player()->query_skill("qiufeng-chenfa", 1) >= 40 )
        return __DIR__"qiufeng-chenfa/" + action;
}
