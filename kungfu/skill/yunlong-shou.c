// yunlongshou.c -������
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+GRN+"��ľ�Ա�"+NOR+"����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
    "force" : 200,
    "lvl" : 0,
    "skill_name" : GRN "��ľ�Ա�" NOR,
        "damage_type" : "ץ��"
]),
([  "action" : "�ں��������У�$Nʹһ�С�"+RED+"����׽Ӱ"+NOR+"����˫���繳��ꫣ�����$n��$l",
    "force" : 250,
    "lvl"   : 20,
    "skill_name" : RED "����׽Ӱ" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$N˫ȭ���裬һʽ��"+HIY+"����ȥ��"+NOR+"�������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
    "force" : 250,
    "lvl" : 30,
    "skill_name" : HIY "����ȥ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�"+HIG+"ʮָǬ��"+NOR+"������$n��$l",
    "force" : 300,
    "lvl"   : 40,
    "skill_name" : HIG "ʮָǬ��" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$N���ֻ��أ�Ҹ�º��գ�������ָ�繳��һ�С�"+HIW+"������ȱ"+NOR+"������$n�Ķ���",
    "force" : 260,
    "lvl"   : 50,
    "skill_name" : HIW "������ȱ" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$N����б��$n����֮�䣬һ�С�"+HIB+"��������"+NOR+"��������ȡĿ�����ַ���$n���ɲ�",
    "force" : 300,
    "lvl"   : 60,
    "skill_name" : HIB "��������" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$Nһ����ָ$n�Ľ�����һ�С�"+MAG+"��������"+NOR+"��������ץ��$n���еı���",
    "force" : 350,
    "lvl"   : 70,
    "skill_name" : MAG "��������" NOR ,     
    "damage_type" : "ץ��"
]),
([  "action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�"+YEL+"��������"+NOR+"��ʹ$n��������",
    "force" : 400,
    "lvl"   : 80,
    "skill_name" : YEL "��������" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$Nһ�ֶ����צ��һ��ָ�أ�һ�С�"+HIG+"���Ƽ���"+NOR+"��,��������$n��ȫ��",
    "force" : 420,
    "lvl"   : 90,
    "skill_name" : HIG "���Ƽ���" NOR,      
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+WHT+"��������"+NOR+"����ȭ���������֣��������ޣ�����������$n�ĵ���",
    "force" : 460,
    "lvl" : 95,
    "skill_name" : WHT "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N���������ʹһʽ��"+HIW+"��������"+NOR+"��������΢��,��������$n��$l",
    "force" : 490,
    "lvl" : 100,
    "skills_name" : HIW "��������" NOR,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 100;  }
int valid_combine(string combo) { return combo=="yunlong-zhua"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������ֱ�����֡�\n");
    if ((int)me->query_skill("yunlong-shengong", 1) < 50)
        return notify_fail("��������񹦻�򲻹����޷�ѧ�����֡�\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����֡�\n");
    if ((int)me->query("max_neili") < 250)
        return notify_fail("�������̫�����޷��������֡�\n");
    if ((int)me->query_skill("unarmed",1) <30)
        return notify_fail("��Ļ����ַ���򲻹����޷�ѧ�����֡�\n");
    if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-shou",1))
        return notify_fail("��������ķ���򲻹����޷�����ѧ�����֡�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yunlong-shou", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i-1]["lvl"])
            return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("yunlong-shou",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("������������������֡�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-shou/" + action;
}
