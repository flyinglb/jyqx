// nianhua-zhi.c -�黨ָ
inherit SKILL;
mapping *action = ({
([  "action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ��"+HIC+"ƿ������"+NOR+"������$n��$l",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : HIC "ƿ������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�������У�һʽ��"+HIW+"��÷����"+NOR+"������ָ��Ҹ������ָ��$n����ǰ",
    "force" : 70,
    "lvl" : 12,
    "skill_name" : "��÷����",
        "damage_type" : "����"
]),
([  "action" : "$N����б�У����ְ��ƣ�����һʽ��"+YEL+"�����ʾ�"+NOR+"������$n��$l����",
    "force" : 90,
    "lvl" : 17,
    "skill_name" : YEL "�����ʾ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫Ŀ΢����һʽ��"+BLU+"¶��б��"+NOR+"����˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
    "force" : 120,
    "lvl" : 24,
    "skill_name" : BLU "¶��б��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+BLK+"���³���"+NOR+"�������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
    "force" : 160,
    "lvl" : 36,
    "skill_name" : BLK "���³���" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��"+HIG+"Ҷ������"+NOR+"����ָ��$n�������Ѩ",
    "force" : 210,
    "lvl" : 50,
    "skill_name" : HIG "Ҷ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫�Ʒ��ɣ�һʽ��"+HIY+"������"+NOR+"����ָ�˱ų�����������������$n��ȫ��",
    "force" : 270,
    "lvl" : 70,
    "skill_name" : HIY "������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+YEL+"������˪"+NOR+"������ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
    "force" : 340,
    "lvl" : 84,
    "skill_name" : YEL "������˪" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+WHT+"٤Ҷ΢Ц"+NOR+"����˫��ʳָ���棬ָ�����һ�����������$n��$l",
    "force" : 420,
    "lvl" : 95,
    "skill_name" : WHT "٤Ҷ΢Ц" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����������ǰ��һʽ��"+YEL+"��"+BLU+"��"+RED+"�黨"+NOR+"��������ʳָ��סĴָ���������$nһ��",
    "force" : 510,
    "lvl" : 112,
    "skill_name" : RED "�����黨" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 122;  }
int valid_combine(string combo) { return combo=="sanhua-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("ѧ�黨ָ������֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�ѧ�黨ָ��\n");
if (me->query_skill("finger", 1) <=me->query_skill("nianhua-zhi", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
    return notify_fail("�������������򲻹����޷�ѧ�黨ָ��\n");

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
        level   = (int) me->query_skill("nianhua-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-random(level/3);
    a_action["attack"]  = level/3;
    a_action["damage"] = level/3;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���黨ָ������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("��������������黨ָ��\n");
    me->receive_damage("qi", 40);
    me->add("neili", -20);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"nianhua-zhi/" + action;
}
