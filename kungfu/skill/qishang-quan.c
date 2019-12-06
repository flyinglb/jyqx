// qishang-quan.c -����ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$N������ȭ��˫ȭ���ƶ�����ֻ�о���Ƣ����������,һ�С������߽⡹�Ѿ�����$n��$l",
        "force" : 180,
        "lvl" : 0,
        "skill_name" : "�����߽�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ϼ��͡�������������˫ȭ�໥��������ȭ�ƻ������ش���$n�����ţ���ž����",
        "force" : 200,
        "lvl" : 35,
        "skill_name" : "���ϼ���",
        "damage_type" : "����"
]),
([      "action" : "$N��Ȼ����ӭ��$n��ʹ��һ�С�ˮ��ʯ������ȭ���������·���ֱ��$n����$n�����ٳ�",
        "force" : 230,
        "lvl" : 75,
        "skill_name" : "ˮ��ʯ��",
        "damage_type" : "����"
]),
([      "action" : "$Nȭ������ת��������$n��������֮�ʣ���Ȼ�����ھ�������һʽ����ľ���ۡ�����$nѸ�ٺ��",
        "force" : 270,
        "lvl" : 130,
        "skill_name" : "��ľ����",
        "damage_type" : "����"
]),
([      "action" : "$N����������ȭ�������ӷ���������һʽר�������������ġ��������⡹���һȭ��$n��ȥ��",
        "force" : 320,
        "lvl" : 160,
        "skill_name" : "",
        "damage_type" : "��������"
]),
([      "action" : "$N������עȫ���������������ֱ�����ȭ��ʹ��������ȭ��������������֮һ���������������Ǻ��Ҵ����ȴ�ǹ������ؾ�֮��",
        "force" : 380,
        "lvl" : 178,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��������������ȭ��֮ǿ��νһʱ������һʽ��������Υ��������Ĵ��Կ����������ƿ�֮��",
        "force" : 450,
        "lvl" : 200,
        "skill_name" : "������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫�����޷�������ȭ��\n");
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
    level   = (int) me->query_skill("qishang-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_level(){   return 200;  }

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ȭ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -15);
        return 1;
}
string perform_action_file(string action)
{
        return "/kungfu/skill/qishang-quan/" + action;
}
