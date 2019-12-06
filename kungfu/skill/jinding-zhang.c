// jinding-zhang.c ������
// Oct. 9 1997 by That
inherit SKILL;

mapping *action = ({
([      "skill_name" : "������̩" ,
        "action" : "$N����΢�Σ�һ�С�������̩�������������$nֻ����һ��ů��Ϯ��$l",
        "force" : 100,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl"   : 0,
]),
([      "skill_name" : "��������" ,
        "action" : "$N˫�ֱ�ã���ָ�ᵯ��һ�С��������项��������·������ʮ����ץ��$n��$l",
        "force" : 120,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl"   : 11,
]),
([      "skill_name" : "�����" ,
        "action" : "$N����ǰ��������ٿ��������ͷ�һ�С�����ơ�����ץ��$n��$l",
        "force" : 150,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl"   : 22,
]),
([      "skill_name" : "������ɳ" ,
        "action" : "$N����Ȧת�����$n�����֣������Ƴ������������Ļ���һ�С�������ɳ�����͵ػ���$n���°�",
        "force" : 200,
        "dodge" : 25,
        "damage_type" : "����",
        "lvl"   : 33,
]),
([      "skill_name" : "�׶�����" ,
        "action" : "$N�������ף�һ�����ȣ���$nһ㶼䣬����һ�С��׶���������ֱ��$n��$l",
        "force" : 100,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl"   : 44,
]),
([      "skill_name" : "�𶥷��" ,
        "action" : "$N˫��ƽ����ȭ����¶΢Ц��$n��㱼俴��$N����Ϊ�������$N���������һ�С��𶥷�⡹��֪��������ʵ���Ʒ��Ѿ�Ϯ��",
        "force" : 200,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl"   : 55,
]),
([      "skill_name" : "���Ľ�ħ" ,
        "action" : "$Nһ������ׯ�ϣ�ʹ�������Ľ�ħ����������磬����$nƯ�Ʋ���",
        "force" : 230,
        "parry" : 20,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl"   : 66,
]),
([      "skill_name" : "����˻�" ,
        "action" : "$Nȫ�����ߣ�˫�ۼ��裬��Ϊ�����Ӱ��һ�С�����˻ġ�����ǵ�Ϯ��$nȫ�������Ѩ",
        "force" : 300,
        "parry" : 5,
        "dodge" : 30,
        "damage_type" : "����",
        "lvl"   : 77,
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
                return notify_fail("����ټ�ׯ�ķ���򲻹��������������ơ�\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i-1]["lvl"])
                return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int)me->query_skill("jinding-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if (me->query_skill("jinding-zhang", 1) < 100)
                me->receive_damage("qi", 10);
        else
        me->receive_damage("qi", 20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}
