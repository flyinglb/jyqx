// xingyi-zhng ��ת������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С����α�Ӱ����˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 160,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "���α�Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴������ʹһ�С����ǵ�㡹����$n��$l��ȥ",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 30,
        "skill_name" : "���ǵ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ȭ����ǰ��󻮻���һ�С������Ƕ�������$n��$l",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 60,
        "skill_name" : "�����Ƕ�",
        "damage_type" : "����"
]),
([      "action" : "$N�����黮������һ�ǡ��嶷�ǳ�������$n������",
        "force" : 360,
        "dodge" : 20,
        "lvl" : 90,
        "skill_name" : "�嶷�ǳ�",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����������ǡ������ֻ���$n��$l�����ֹ���$n���ɲ�",
        "force" : 410,
        "dodge" : 250,
        "lvl" : 110,
        "skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
/*
int valid_combine(string combo,object me) { 
         object me;
         me = this_player();
       if ((me->query("family/family_name") == "����Ľ��") && (me->query("family/generation") == 2))
     return combo=="canhe-zhi"; 
}
*/
int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");
if ( myfam["master_name"] == "Ľ�ݲ�")
                 return combo=="canhe-zhi";
}
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ת�����Ʊ�����֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ��ת�����ơ�\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�����ת�����ơ�\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xingyi-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("���������������ת�����ơ�\n");
        me->receive_damage("jing", 25);
        me->add("neili", -5);
        return 1;
}

