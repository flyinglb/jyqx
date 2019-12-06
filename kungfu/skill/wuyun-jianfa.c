// wuyun-jianfa.c
inherit SKILL;

mapping *action = ({
([      "action" : "$N��Сָ�ᵯ��һ�С����ϡ���Ȼ����$n�ĺ���",
        "force" : 120,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��������ָ�������޵�һ���������Ҳ���һ����[����]�ѽ�$n����
",
        "force" : 140,
        "dodge" : 15,
        "damage" : 70,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ָ���ӣ�һʽ[����]���εĴ���$n������",
        "force" : 170,
        "dodge" : 15,
        "damage" : 80,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$N�����н���ɨ��ͬʱ�������������Ƶļ���������һ��[֧��]",
        "force" : 190,
        "dodge" : 10,
        "damage" : 90,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������ϡ��������������ߣ���ͬ��������������������$n
��$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 100,
        "lvl" : 29,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
//        if ((int)me->query_skill("wuzheng-xinfa", 1) < 20)
//                return notify_fail("��������ķ���򲻵���\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
            level   = (int) me->query_skill("wuyun-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("��������������������ҽ���\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wuyun-jianfa/" + action;
}

