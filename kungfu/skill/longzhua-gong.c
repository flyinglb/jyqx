// longzhua-gong.c -��צ��
inherit SKILL;
mapping *action = ({
([  "action" : "�ں��������У�$Nʹһ�С�"+YEL+"����ʽ"+NOR+"����˫���繳��ꫣ�����$n��$l",
    "force" : 100,
    "lvl"   : 0,
    "skill_name" : YEL "����ʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N�͵���ǰԾ����һ�С�"+RED+"׽Ӱʽ"+NOR+"���������߳���˫��ץ��$n������",
    "force" : 110,
    "lvl"   : 6,
    "skill_name" : RED "׽Ӱʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�"+MAG+"����ʽ"+NOR+"������$n��$l",
    "force" : 120,
    "lvl"   : 12,
    "skill_name" : MAG "����ʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N���������������ڻӣ�һ�С�"+WHT+"����ʽ"+NOR+"������$n�ؿ�",
    "force" : 140,
    "lvl"   : 18,
    "skill_name" : WHT "����ʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N�������գ�����������ɽ��һ�С�����ʽ�����͵ػ���$n��$l",
    "force" : 160,
    "lvl"   : 24,
    "skill_name" : "����ʽ" ,       
    "damage_type" : "����"
]),
([  "action" : "$N�ڲ���ǰ�����ֻ��أ�����̽����һ�С�����ʽ������$n���ɲ�",
    "force" : 190,
    "lvl"   : 30,
    "skill_name" : "����ʽ" ,       
    "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С�����ʽ����������$n��$l",
    "force" : 220,
    "lvl"   : 35,
    "skill_name" : "����ʽ" ,       
    "damage_type" : "����"
]),
([  "action" : "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С�"+RED+"��ȱʽ"+NOR+"������$n�Ķ���",
    "force" : 260,
    "lvl"   : 40,
    "skill_name" : RED "��ȱʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N����б��$n����֮�䣬һ�С�"+YEL+"����ʽ"+NOR+"��������ȡĿ�����ַ���$n���ɲ�",
    "force" : 300,
    "lvl"   : 45,
    "skill_name" : YEL "����ʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$Nһ����ָ$n�Ľ�����һ�С�"+HIC+"�ὣʽ"+NOR+"����һ������ץ��$n",
    "force" : 350,
    "lvl"   : 50,
    "skill_name" : HIC "�ὣʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�"+HIW+"����ʽ"+NOR+"��ʹ$n��������",
    "force" : 400,
    "lvl"   : 55,
    "skill_name" : HIW "����ʽ" NOR ,       
    "damage_type" : "����"
]),
([  "action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�"+RED+"׷"+HIW+"��"+RED+"ʽ"+NOR+"����������$n��ȫ��",
    "force" : 460,
    "lvl"   : 60,
    "skill_name" : RED "׷��ʽ" NOR ,       
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="qianye-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����צ��������֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����צ����\n");
 if (me->query_skill("claw", 1) <=me->query_skill("longzhua-gong", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ��צ����\n");

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
    level   = (int) me->query_skill("longzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����צ��������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("���������������צ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
