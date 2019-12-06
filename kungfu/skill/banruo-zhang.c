// banruo-zhang.c -������
inherit SKILL;
mapping *action = ({
([  "action" : "$Nǰ���߳������Ƚż��أ�һʽ��"+RED+"��ճ���"+NOR+"��������ֱ��������$n����������·",
    "force" : 150,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" :  RED "��ճ���" NOR
]),
([  "action" : "$N���ƻ�һ��Բ��һʽ��"+MAG+"�������"+NOR+"��������б������������$n����ǰ��Ѩ",
    "force" : 160,
    "dodge" : -10,
    "damage_type" : "����",
    "lvl" : 12,
    "skill_name" :  MAG "�������" NOR
]),
([  "action" : "$Nʹһʽ��"+HIW+"�ƶ�����"+NOR+"�������������������ɺ����һ��˦����ն��$n��$l",
    "force" : 170,
    "dodge" : -15,
    "damage_type" : "����",
    "lvl" : 18,
    "skill_name" : HIW "�ƶ�����" NOR
]),
([  "action" : "$N���ƻ��أ���ȭ�����󷢣�һʽ��"+WHT+"��������"+NOR+"������������$n��$l",
    "force" : 185,
    "dodge" : -20,
    "damage_type" : "����",
    "lvl" : 24,
    "skill_name" : WHT "��������" NOR
]),
([  "action" : "$Nʹһʽ��"+HIB+"�����"+NOR+"����ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
    "force" : 200,
    "dodge" : -25,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : HIB "�����" NOR
]),
([  "action" : "$N���Ʊ�������һ������һʽ��"+HIC+"���б���"+NOR+"����˫�Ƽ�����$n�ļ�ͷ",
    "force" : 220,
    "dodge" : -35,
    "damage_type" : "����",
    "lvl" : 36,
    "skill_name" : HIC "���б���" NOR 
]),
([  "action" : "$N���ϸ߸�Ծ��һʽ��"+CYN+"��ɽ��ˮ"+NOR+"�����Ӹ����£���������$n��ȫ��",
    "force" : 240,
    "dodge" : -60,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : CYN "��ɽ��ˮ" NOR
]),
([  "action" : "$Nʹһʽ��"+WHT+"ժ�ǻ���"+NOR+"��������������˫�����֣�һ������$n��$l�ȥ",
    "force" : 270,
    "dodge" : -80,
    "damage_type" : "����",
    "lvl" : 48,
    "skill_name" : WHT "ժ�ǻ���" NOR
]),
([  "action" : "$N�������»��أ�һʽ��"+YEL+"��������"+NOR+"������Ȼ��Ϊ�������꣬����$n",
    "force" : 310,
    "dodge" : -100,
    "damage_type" : "����",
    "lvl" : 54,
    "skill_name" : YEL "��������" NOR
]),
([  "action" : "$Nһʽ��"+BLU+"��շ�ħ"+NOR+"����˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ�����˰���ӿ����",
    "force" : 360,
    "dodge" : -120,
    "damage_type" : "����",
    "lvl" : 60,
    "skill_name" : BLU "��շ�ħ" NOR
])
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="yizhi-chan"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�����ơ�\n");
    if ((int)me->query("max_neili") < 150)
        return notify_fail("�������̫�����޷��������ơ�\n");
    if (me->query_skill("unarmed", 1) <= me->query_skill("banruo-zhang", 1) 
    && me->query_skill("parry", 1) <= me->query_skill("banruo-zhang", 1) )
        return notify_fail("��Ļ��������δ�����޷�����������书��\n");
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
    level = (int)me->query_skill("banruo-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("������������������ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
