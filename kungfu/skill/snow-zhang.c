// snow-zhang.c
#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
    ([  "action":       "$Nһ��"+(order[random(13)])+"��÷��С�á�"NOR"��˫�ֻ�������,��ƮƮ�ص���$n$l", 
        "parry": -10,
        "force": 40,
        "damage_type": "����"
        ]),
    ([  "action":       "$N��ȭƽ��,��ȭ���»��˸��뻡,һ��"+(order[random(13)])+"��÷�޺��ӡ�"NOR",��ȡ$n��$l",
        "dodge": 10,
        "force": 50,
        "damage_type": "����"
    ]),
    ([  "action":     "$Nһ��"+(order[random(13)])+"����ѩ��÷��"NOR",˫������о���,�������ǰ�����$n$l",
        "dodge": 10,
        "force": 60,
        "parry": 5,
        "damage_type": "����"
        ]),
    ([  "action":       "$N����һ��"+(order[random(13)])+"��˪ѩ���졹"NOR",ɢ��ɭɭ����,����$n��$l",
        "dodge": 20,
        "parry": 10,
        "force": 80,
        "damage_type": "����"
        ]),
    ([  "action":       "$Nʹһ��"+(order[random(13)])+"����ѩ��÷��"NOR"��������ת,��������$n$l",
        "dodge": 10,
        "parry": 20,
        "force": 100,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һЦ,�������,һʽ"+(order[random(13)])+"������Ʈ÷��"NOR"��Χ��$n��$l��ƮƮ��������",
        "dodge":  10,
        "force": 140,
        "damage_type": "����"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ѩӳ÷�Ʊ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���ϰ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 10);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"snow-zhang/" + action;
}

