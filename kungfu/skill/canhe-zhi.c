// canhe-zhi.c �κ�ָ
inherit SKILL;

mapping *action = ({
([      "action" : "$N���缤����˫ָ������ã�һ�С�Ŀ��ʶ�����׺ݵ���$n��$l��ȥ",
        "force" : 100,
        "dodge" : 5,
        "damage": 10,
		"lvl" : 0,
		"weapon" : "ָ��",
        "skill_name" : "Ŀ��ʶ��",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʮָ���·ַɣ�һ�С������㾦����˫ֱָȡ$n��$l",
        "force" : 130,
        "dodge" : 8,
		"damage": 15,
		"weapon" : "ָ��",
        "lvl" : 20,
        "skill_name" : "�����㾦",
        "damage_type" : "����"
]),
([      "action" : "$Nʮָ���������ʵ��һ�С���˷���롹��ǰ�����ң�˲Ϣ����$n����������",
        "force" : 170,
        "dodge" : 5,
		"damage": 20,
		"weapon" : "ָ��",
        "lvl" : 40,
        "skill_name" : "��˷����",
        "damage_type" : "����",
]),
([      "action" : "$N�����ڿն���һ�С��ܳ���������������죬��$n��$l�Ͳ���ȥ",
        "force" : 200,
        "dodge" : 0,
        "damage": 25,
		"weapon" : "ָ��",
		"lvl" : 60,
        "skill_name" : "�ܳ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�������������ߵ�$n��ǰ��һ�С����ϲ�����������$n��$l",
        "force" : 220,
        "dodge" : 15,
		"damage": 30,
		"weapon" : "ָ��",
        "lvl" : 70,
        "skill_name" : "���ϲ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��˱����᡹������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 80,
        "skill_name" : "�˱�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ�С���н��������һ����ɽ������������ֱ��$n$l",
        "force" : 360,
        "dodge" : -5,
        "lvl" : 90,
        "skill_name" : "��н����",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ���м�ת��һ�С����μ�����ʮָ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 420,
        "dodge" : -15,
        "lvl" : 100,
        "skill_name" : "���μ�",
        "damage_type" : "����"
]),
});

int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");
         if ( myfam["master_name"] == "Ľ�ݲ�")
                 return combo=="xingyi-zhang";
}
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
/*
int valid_combine(string combo) {
         object me;
         me = this_player();
       if ((me->query("family/family_name") == "����Ľ��") && (me->query("family/generation") == 2))
     return combo=="xingyi-zhang"; 
}
*/
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ�κ�ָ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����κ�ָ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 80, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("canhe-zhi", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["canhe-zhi"])
                while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("jing", 20);
        me->add("neili", -10);
		return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}
