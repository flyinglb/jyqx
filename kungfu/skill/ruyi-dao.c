// ruyi-dao.c - ���⵶��

inherit SKILL;
mapping *action = ({
([      "action" : "$Nһ�ĵ�����һ�С�"+WHT+"��������"+NOR+"�����͵�һ��ת������$wֱ��$nնȥ",
        "force"         : 80,
        "lvl"           : 0,
        "skill_name"    : WHT "��������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N�����е�$wһ�һ�С�"+YEL+"���·ת"+NOR+"�������еĵ�һ����ת��ֱ����$n��$l",
        "force"         : 100,
        "lvl"           : 10,
        "skill_name"    : YEL "���·ת" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N���ζ�Ȼ�������ߣ�һ�С�"+RED+"�������"+NOR+"����������磬����$wն��$n��$l",
        "force"         : 120,
        "lvl"           : 20,
        "skill_name"    : RED "�������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$Nһ�С�"+HIW+"��������"+NOR+"����������Ȼ�θ����ߣ�����$wһ��ƽ����$n��$l��ȥ��",
        "force"         : 140,
        "lvl"           : 30,
        "skill_name"    : HIW "��������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N����һԾ������$wһ�С�"+HIY+"���к��"+NOR+"����ƮƮ����$n��$lҪ����ȥ",
        "force"         : 160,
        "lvl"           : 40,
        "skill_name"    : HIY "���к��" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N����$w����һ�֣����������һ�С�"+BOLD+"��������"+NOR+"��������$n$l��ȥ",
        "force"         : 180,
        "lvl"           : 50,
        "skill_name"    : BOLD "��������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N�ᵶ��ǰ������һת������$wʹһ�С�"+CYN+"�չ����"+NOR+"������һ���⻡ն��$n��$l",
        "force"         : 200,
        "lvl"           : 60,
        "skill_name"    : CYN "�չ����" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$nֻ����ǰһ����$Nһ�С�"+HIM+"��������"+NOR+"����$wЮ��������Ѹ�Ϳ���$n��$l",
        "force"         : 220,
        "lvl"           : 70,
        "skill_name"    : HIM "��������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N��$w����һȦ��һ�С�"+HIC+"������"+NOR+"����$nֻ����ȫ��������һ�ŵ���֮�С�",
        "force"         : 240,
        "lvl"           : 80,
        "skill_name"    : HIC "������" NOR,
        "damage_type"   : "����"
]),
([      "action" : "$N����һת��һ�С�"+HIB+"��ң����"+NOR+"����$w���ⲻ�������п���$n��$lҪ��",
        "force"         : 260,
        "lvl"           : 100,
        "skill_name"    : HIB "��ң����" NOR,
        "damage_type"   : "����"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 100;  }
int valid_combine(string combo) { return combo=="fumo-jian"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("beiming-shengong", 1) < 20 )
    if ((int)me->query_skill("yijing-force", 1) < 20)
        return notify_fail("��ı�ڤ�񹦻��̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("ruyi-dao", 1))
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
    level   = (int) me->query_skill("ruyi-dao", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������⵶����\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ruyi-dao/" + action;
}

