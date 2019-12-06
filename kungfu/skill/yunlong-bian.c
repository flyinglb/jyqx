// yunlong-bian.c �����޷�
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N����һ�һ�С�"+YEL+"����ٵ�"+NOR+"��������$w���ñ�ֱ����׼$n��ͷ����",
    "force":        100,
    "lvl" : 0,
    "skill_name" : YEL "����ٵ�" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N����һת��һ�С�"+RED+"�����ĺ�"+NOR+"��������$w��������ڿ�һ���͵ػ���$n̫��Ѩ",
    "force":        150,
    "lvl" : 10,
    "skill_name" : RED "�����ĺ�" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N৵�һ�����ޣ�һ�С�"+YEL+"������ˮ"+NOR+"��������$w���ñ�ֱ������$n˫��",
    "force":        200,
    "lvl" : 20,
    "skill_name" : YEL "������ˮ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N������ң�һ�С�"+BLU+"���Ƽ���"+NOR+"��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
    "force":        200,
    "lvl" : 30,
    "skill_name" : BLU "���Ƽ���" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N��������һ�С�"+MAG+"��ɽ��ʯ"+NOR+"��������$w��һ��ͭ����ֱ����$n",
    "force":        250,
    "lvl" : 40,
    "skill_name" : MAG "��ɽ��ʯ" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N����һ�ӣ�һ�С�"+HIC+"���Χ��"+NOR+"��������$wֱ����$n����",
    "force":        300,
    "lvl" : 50,
    "skill_name" : HIC "���Χ��" NOR,
    "damage_type":  "����"
]),
([  "action":       "$N�߸�Ծ��һ�С�"+YEL+"��Į����"+NOR+"��������$w��ֱ��$n��ͷ����",
    "force":        350,
    "lvl" : 60,
    "skill_name" : YEL "��Į����" NOR,
    "damage_type":  "����"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    object weapon;
    if( (int)me->query("max_neili") < 200 )
        return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�\n");
    if ((int)me->query_skill("force", 1) < 40)
        return notify_fail("��Ļ����ڹ����̫ǳ��\n");
    if ( !objectp(weapon = me->query_temp("weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
        return notify_fail("���������һ�����Ӳ������޷���\n");
    if (me->query_skill("whip", 1) <=me->query_skill("yunlong-bian", 1))
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
    level   = (int) me->query_skill("yunlong-bian",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("������������������޷���\n");
    me->receive_damage("qi", 5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-bian/" + action;
}
