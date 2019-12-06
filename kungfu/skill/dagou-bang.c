// dagou-bang.c
inherit SKILL;
mapping *action = ({
([  "action": "$Nʹ��һ�С�"+BLK+"����˫Ȯ"+NOR+"��������$w���������������$n��$l",
    "force" : 50,
    "lvl" : 1,
    "damage_type": "����"
]),
([  "action": "$N����$w���һζ���һ�С�"+RED+"����Ѱ��"+NOR+"����$n��$l��ȥ",
    "force" : 100,
    "lvl" : 33,
    "damage_type": "����"
]),
([  "action": "$N����$w���Ӹ�����ʹһ�С�"+GRN+"��ݾ���"+NOR+"������$n��$l",
    "force" : 180,
    "lvl" : 66,
    "damage_type": "����"
]),
([  "action": "$Nʩ����"+YEL+"��������"+NOR+"����$w����������$n��ȥ",
    "force" : 250,
    "lvl" : 100,
    "damage_type": "����"
]),
});
int practice_level(){   return 100;  }
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("dagou-bang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    else
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level=me->query_skill("dagou-bang",1);
    if (random(me->query_skill("staff")) > 300 &&
        me->query_skill("force") > 60 &&
        me->query("neili") > 100 &&
        (string)weapon->query("id") == "yuzhu zhang" ) {
        me->add("neili", -100);
        return ([
        "action": "$N�������һ����â������������ʹ����"+HIC+"�����޹�"+NOR+"��������ǵذ㹥��$n",
        "attack": 100,
        "damage": 500,
        "dodge": -level*2,
        "force" : 300,
        "damage_type": "����"]);
    }
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
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
        return notify_fail("��������������򹷰�����\n");
    me->receive_damage("qi", 40);
    return 1;
 }


string perform_action_file(string action)
{
    return __DIR__"dagou-bang/" + action;
}
