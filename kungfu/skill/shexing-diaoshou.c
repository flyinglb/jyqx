
// shexing-diaoshou.c ���ε���
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+RED+"���߳���"+NOR+"����������Σ���������ͻȻ����$n�ı����Ѩ",
    "force" : 90,
    "lvl" : 0,
    "skill_name" : RED "���߳���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����һ�Σ�һʽ��"+YEL+"��ͷ��β"+NOR+"������������$n�ļ�ͷ����ȭ����$n���ؿ�",
    "force" : 120,
    "lvl" : 24,
    "skill_name" : YEL "��ͷ��β" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIG+"��������"+NOR+"�������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
    "force" : 130,
    "lvl" : 46,
    "skill_name" : HIG "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�������У�����ֱ����һʽ��"+HIY+"������Ӱ"+NOR+"������Ʈ��������$n������",
    "force" : 160,
    "lvl" : 68,
    "skill_name" : HIY "������Ӱ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+BLK+"�������"+NOR+"������ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
    "force" : 200,
    "lvl" : 89,
    "skill_name" : BLK "�������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+GRN+"��������"+NOR+"����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
    "force" : 310,
    "lvl" : 100,
    "skill_name" : GRN "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫�ֱ�ȭ��һʽ��"+YEL+"������ӿ"+NOR+"������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
    "force" : 380,
    "lvl" : 120,
    "skill_name" : YEL "������ӿ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+WHT+"��������"+NOR+"����ȭ���������֣��������ޣ�����������$n�ĵ���",
    "force" : 460,
    "lvl" : 140,
    "skill_name" : WHT "��������" NOR,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����ε��ֱ�����֡�\n");
    if ((int)me->query_skill("hamagong", 1) < 20)
        return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ε��֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷������ε��֡�\n");
    if (me->query_skill("hand", 1) <=me->query_skill("shexing-diaoshou", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    level   = (int) me->query_skill("shexing-diaoshou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����ε��ֱ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("����������������ε��֡�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
