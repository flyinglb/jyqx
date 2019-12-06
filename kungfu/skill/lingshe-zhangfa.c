//lingshe_zhangfa.c �����ȷ�
#include "ansi.h"
inherit SKILL;
mapping *action = ({
([  "action": "$Nʹ��һ�С�"+RED+"���߳���"+NOR+"��������$w�󿪴���ɨ��$n��$l",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : RED "���߳���" NOR,
    "damage_type": "����"
]),
([  "action": "$N����$w������죬һ�С�"+MAG+"ҡͷ��β"+NOR+"����$n��$l��ȥ",
    "force" : 140,
    "lvl" : 20,
    "skill_name" : MAG "ҡͷ��β" NOR,
    "damage_type": "����"
]),
([  "action": "$N����$w���Ӹ�����ʹһ�С�"+HIW+"������"+BLU+"��"+NOR+"������$n��$l",
    "force" : 180,
    "lvl" : 30,
    "skill_name" : HIW "�����½�" NOR,
    "damage_type": "����"
]),
([  "action": "$Nһ�С�"+YEL+"����ͦ��"+NOR+"��������$w����ɨ��$n��$l",
    "force" : 220,
    "lvl" : 40,
    "skill_name" : YEL "����ͦ��" NOR,
    "damage_type": "����"
]),
([  "action": "$Nʹ��һ�С�"+YEL+"��������"+NOR+"����$w�����ػ���$n��$lɨȥ",
    "force" : 260,
    "lvl" : 50,
    "skill_name" : YEL "��������" NOR,
    "damage_type": "����"
]),
([  "action": "$N����$wһ�ӣ�ʹ��һ�С�"+BLU+"�߲�����"+NOR+"�����������ɨ��$n��$l",
    "force" : 300,
    "lvl" : 60,
    "skill_name" : BLU "�߲�����" NOR,
    "damage_type": "����"
]),
([  "action": "$Nʹ��һ�С�"+RED+"������"+YEL+"ɽ"+NOR+"�����߾�����$w����ͷ����$n��$l",
    "force" : 340,
    "lvl" : 80,
    "skill_name" : RED "������ɽ" NOR,
    "damage_type": "����"
]),
([  "action": "$Nʹ��һ�С�"+RED+"���߳�"+BLK+"��"+NOR+"��������$w��һ̽��ֱɨ$n��$l",
    "force" : 380,
    "lvl" : 100,
    "skill_name" : RED "���߳���" NOR,
    "damage_type": "����"
]),
});
int practice_level(){   return 100;  }
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
    level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;

}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 70)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("lingshe-zhangfa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("������������������ȷ���\n");
    me->receive_damage("qi", 20);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hamagong")) > 10 ) 
    {
    victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
    victim->query_condition("snake_poison"));
        tell_object(victim, HIG "����ñ����еĵط�һ����ľ��\n" NOR );
        tell_object(victim, HIG "ԭ���Ǳ���ͷ�ܳ��Ķ���ҧ��һ�ڣ�\n" NOR );
    }
}
