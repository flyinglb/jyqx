// yingzhua-gong.c -ӥצ��
inherit SKILL;
mapping *action = ({
([  "action" : "$Nȫ��εض��𣬰����һ�����һʽ��"+YEL+"��ӥϮ��"+NOR+"����Ѹ�͵�ץ��$n��$l",
    "force" : 100,
    "lvl" : 0,
    "skills_name" : YEL "��ӥϮ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����ֱ����˫��ƽ�죬һʽ��"+HIY+"��ӥչ��"+NOR+"����˫צһǰһ��£��$n��$l",
    "force" : 120,
    "lvl" : 10,
    "skills_name" : HIY "��ӥչ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIB+"�γ���"+NOR+"����ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
    "force" : 150,
    "lvl" : 20,
    "skills_name" : HIB "�γ���" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫צ�����Ͼ٣�ʹһʽ��"+MAG+"ӭ������"+NOR+"����һ�����ֱ�Ϯ��$n����Ҹ����",
    "force" : 190,
    "lvl" : 30,
    "skills_name" : MAG "ӭ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nȫ�������ǰ��һʽ��"+YEL+"������צ"+NOR+"������צͻ�������Ȱ�ץ��$n���ؿ�",
    "force" : 250,
    "lvl" : 40,
    "skills_name" : YEL "������צ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N���ػ��У�һʽ��"+HIW+"����հ��"+NOR+"��������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
    "force" : 310,
    "lvl" : 50,
    "skills_name" : HIW "����հ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��������צ���棬һʽ��"+YEL+"��������"+NOR+"���������������ƿն�����Ѹ���ޱȵػ���$n",
    "force" : 380,
    "lvl" : 55,
    "skills_name" : YEL "��ӥϮ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�ڿո߷����ɣ�һʽ��"+HIG+"ӥ������"+NOR+"��������ж�ʱ�Գ�һ������צӰ����������$n",
    "force" : 470,
    "lvl" : 60,
    "skills_name" : HIG "��ӥϮ��" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="fengyun-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ӥצ��������֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���ӥצ����\n");
if (me->query_skill("claw", 1) <=me->query_skill("yingzhua-gong", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧӥצ����\n");
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
        level   = (int) me->query_skill("yingzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level*2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ӥצ��������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������ӥצ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
