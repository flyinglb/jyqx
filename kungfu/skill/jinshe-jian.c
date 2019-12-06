// jinshe-jianfa.c ���߽���
//  

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        HIC "ͻȻ֮�䣬$n�����߶�����󻬳����������$N��һ�С�\n", NOR
        HIC "$n�ֱۻ�ת������$w�����߰���˹�����\n", NOR
        HIC "$n��$w�����֣�������$N�ļ��ϴ��˹�ȥ��$N���ɾ���һ�����⡣\n", NOR
        HIC "$n����Ʈ�����Ʋ���$N����󣬶����$N��һ�С�\n", NOR
        HIC "$N���һ�����͵ع��˹�ȥ��ȴ��$n���岻��˼���ת�˼����䣬��������С�\n", NOR
        HIC "$N�۾�һ����$nͻȻ�������״����������������С�\n", NOR 
});


mapping *action = ({
([      "action": "$NͻȻ������΢Ц������Խ��Խ�����������˵��ϣ�����$wȴֱ��$n��ǰ��",
        "force" : 80,
        "dodge" : 40,
        "damage": 80,
        "lvl" : 0,
        "skill_name" : "���΢Ц",
        "damage_type":  "����"
]),
([      "action":"$N�����߶�������$w�Ӳ���˼��ĽǶ���$n�ĺ󱳴�ȥ",
        "force" : 80,
        "dodge" : 60,
        "damage": 100,
        "lvl" : 25,
        "skill_name" : "�����߶�",
        "damage_type":  "����"
]),
([      "action": HIY "ͻȻ�䣬$N���Ϸ������ɽ�⣬$w���ʶ�������$n��ǰ�ػ�ȥ" NOR,
        "force" : 340,
        "dodge" : 20,
        "damage": 200,
        "lvl" : 100,
        "skill_name" :  "���ɽ��",
        "damage_type":  "����"
]),
([      "action":"$Ņ�����죬״��������$w�������ֱ��$nͷ����$nһ���ҽ�",
        "force" : 380,
        "dodge" : 60,
        "damage": 260,
        "lvl" : 110,
        "skill_name" : "̧������",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        int i, level;
        level   = (int) me->query_skill("jinshe-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
//return notify_fail("���߽���ֻ��ͨ����ϰ�����߽��ס���ѧϰ��\n");
    object ob;
    if( (int)me->query_skill("jinshe-jian",1) < 200 )
        return notify_fail("���߽���Ҫ200�����ϲ���������\n");
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("�������������û�а취�����߽�����\n");
    if( !(ob = me->query_temp("weapon"))
        ||(string)ob->query("skill_type") != "sword" )
    return notify_fail("���������һ�ѽ�������������\n");

    return 1;
// modify by risc
}
string perform_action_file(string action)
{
        return __DIR__"jinshe-jian/" + action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
       ||(string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
       ||(string)weapon->query("skill_type") != "sword")
    return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
         return notify_fail("����������������߽�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
