// hujia-dao.c ���ҵ���
// 
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wһ�ᣬ��$n��Ϊ����֮�⣬˭֪���С�"+HIY+"�ɺ�����"+NOR+"��ȴ�ѹ���$n��$l��",
        "force" : 100,
        "dodge" : 30,
        "parry" : -15,
        "damage" : 20,
        "lvl" : 0,
        "skill_name" : "�ɺ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�С�"+HIM+"�ϲ�����"+NOR+"�������ȶԷ�����������$w�Ӳ���ն��$n��$l��",
        "force" : 150,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 10,
        "skill_name" : "�ϲ�����",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�"+HIW+"��ƽ��ӡ"+NOR+"����Ȼ�Ե����ƣ�����$w���¶��ϴ���$n���ز�",
        "force" : 160,
        "dodge" : 5,
        "parry" : -10,
        "damage" : 15,
        "lvl" : 20,
        "skill_name" : "��ƽ��ӡ",
        "damage_type": "����"
]),
([      "action": "$N����������һ�С�"+HIB+"����ժ��"+NOR+"��������$wȴ�����¿���$n���Ҽ硣",
        "force" : 200,
        "dodge" : -20,
        "damage" : 50,
        "lvl" : 50,
        "skill_name" : "����ժ��",
        "damage_type": "����"
]),
([      "action" : "$N����һչ��"+HIG+"���ӷ���"+NOR+"����һ�������ǧ��������$w�Բ���˼��ķ�������$n��$l��",
        "force" : 180,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 75,
        "lvl" : 80,
        "skill_name" : "���ӷ���",
        "damage_type" : "����"
]),
([      "action" : "$N�ӶԷ������ڲ��ˣ�һ�С�"+HIW+"���б���"+NOR+"��������$w��������ֱ����$n��$l��",
        "force" : 210,
        "dodge" : 20,
        "damage" : 120,
        "lvl" : 100,
        "skill_name" : "���б���",
        "damage_type": "����"
]),
([      "action" : "$n��籩��Ĺ��Ʊ�$Nһ�С�"+HIR+"��������"+NOR+"���������⣬����$N����$w������$l��",
        "force" : 250,
        "dodge" : -20,
        "parry" : 20,
        "damage" : 130,
        "lvl" : 150,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "name":         HIY"��������"NOR,
        "action":       "$Nʹ��" +HIY"������������" + HIB"$nֻ����ǰһ�����������������ĵ����ĵ����˵�������\n"NOR
+ "        "+RED"���������ĵ����з·�$N�����Ϊǧ�ֹ�������¶�����΢Ц��\n"NOR +
BLINK HIM"             �۹����$n��$l��ͬʱ���޵Ĺ⻪����$l��"NOR,
        "force" : 300,
        "dodge" : 80,
        "damage" : 250,
        "parry" : 80,
        "lvl" : 200,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

// int valid_combine(string combo) { return combo=="wuka-quan"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("force", 120) < 10)
                return notify_fail("����ڹ����̫ǳ��\n");
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
        level   = (int) me->query_skill("hujia-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!me->query_skill("force", 120) )
                return notify_fail("����ڹ����̫ǳ��\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("������������������ҵ�������\n");

        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hujia-dao/" + action;
}

