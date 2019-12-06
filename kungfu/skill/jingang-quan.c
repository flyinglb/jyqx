// jingang-quan.c -����ȭ
inherit SKILL;
mapping *action = ({
([  "action" : "$N��ϥ���������ֺ�ʮ��һʽ��"+YEL+"������"+NOR+"����˫ȭ���ƶ���������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+RED+"�һ�׶"+NOR+"����˫�������»���ȭ�����棬��ž����",
    "force" : 200,
    "lvl" : 10,
    "skill_name" : RED "�һ�׶" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�ڿշ���һʽ��"+HIW+"�˷���"+NOR+"����˫��˫���������$n�޿ɶ��",
    "force" : 230,
    "lvl" : 20,
    "skill_name" : HIW "�˷���" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫���麬����Ե�³���һʽ��"+BLU+"������"+NOR+"����������$n�Ƴ�",
    "force" : 270,
    "lvl" : 30,
    "skill_name" : BLU "������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��"+HIY+"��ָɽ"+NOR+"��������$n����ǰ���",
    "force" : 320,
    "lvl" : 40,
    "skill_name" : HIY "��ָɽ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+RED+"������"+NOR+"��������ʮָ���$n��ȫ����ʮ����ҪѨ",
    "force" : 380,
    "lvl" : 48,
    "skill_name" : RED "������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��Ŀ���ӣ�˫��������һʽ��"+YEL+"������"+NOR+"��������˷������������ǵ�����",
    "force" : 450,
    "lvl" : 54,
    "skill_name" : YEL "������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ��"+YEL+"����Ц"+NOR+"������Ȼ����$n��ǰ��",
    "force" : 530,
    "lvl" : 60,
    "skill_name" : YEL "����Ц" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�������ȭ��\n");
 if (me->query_skill("cuff", 1) <=me->query_skill("jinggang-quan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ����ȭ��\n");

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
    int i, level;
    mapping a_action;
    level   = (int) me->query_skill("jingang-quan",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level*2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�����������������ȭ��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jingang-quan/" + action;
}

