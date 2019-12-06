// yizhi-chan.c һ��ָ
inherit SKILL;
mapping *action = ({
([  "action" : "$NСָһ��������$n�����䣬һָ������������أ�ֻ��$N����δ�����ڶ�ָ�ѵ���$n$l",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : YEL "һ��ָ" NOR,
    "damage_type" : "����",
]),
([  "action" : "����$N�ֱ۲������������ѵ�ˮ��һ������δ�������ѵ�$n����ҪѨ",
    "force" : 60,
    "lvl" : 50,
    "skill_name" : YEL "һ��ָ" NOR,
    "damage_type" : "����",
]),
([  "action" : "$N����Ծ�����Ƹ��أ��������ʳָ��������$n$l�ϵ�ȥ",
    "force" : 60,
    "lvl" : 100,
    "skill_name" : YEL "һ��ָ" NOR,
    "damage_type" : "����"
]),
([  "action" : "ֻ��$N���л������������ݣ�ٿ��֮�䣬�۽���ȥ����$n$l��һ�㼴�룬�������",
    "force" : 80,
    "lvl" : 150,
    "skill_name" : YEL "һ��ָ" NOR,
    "damage_type" : "����"
]),
([  "action" : "ֻ��$N����$n�����˶��У����ֳ�ָ����������$n��$l",
    "force" : 100,
    "lvl" : 200,
    "skill_name" : YEL "һ��ָ" NOR,
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="unarmed"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��һ��ָ������֡�\n");
    if ((int)me->query_skill("kumu-shengong", 1) < 20)
        return notify_fail("��Ŀ�ľ�񹦻�򲻹����޷�ѧһ��ָ��\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���һָ����\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yiyang-zhi", 1))
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
    int level=me->query_skill("yiyang-zhi",1);
    mapping a_action = action[random( sizeof(action) )];
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level*2;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��һ��ָ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������һָ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

