// qianye-shou.c -����ǧҶ��
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+BLU+"�Ϻ����"+NOR+"����������Σ���������ͻȻ����$n�ı����Ѩ",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : BLU "�Ϻ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����һ�Σ�һʽ��"+YEL+"��������"+NOR+"������������$n�ļ�ͷ����ȭ����$n���ؿ�",
    "force" : 110,
    "lvl" : 13,
    "skill_name" : YEL "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+RED+"��������"+NOR+"�������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
    "force" : 130,
    "lvl" : 25,
    "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�������У�����ֱ����һʽ��"+HIW+"�����Ӱ"+NOR+"������Ʈ��������$n������",
    "force" : 160,
    "lvl" : 37,
    "skill_name" : HIW "�����Ӱ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+BLU+"ˮ��׽��"+NOR+"������ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
    "force" : 200,
    "lvl" : 50,
    "skill_name" : BLU "ˮ��׽��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫ȭ���裬һʽ��"+HIB+"����ȥ��"+NOR+"�������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
    "force" : 250,
    "lvl" : 63,
    "skill_name" : HIB "����ȥ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+BLU+"ˮ�ݳ�û"+NOR+"����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
    "force" : 310,
    "lvl" : 76,
    "skill_name" : BLU "ˮ�ݳ�û" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ֱ�ȭ��һʽ��"+HIB+"����ɷ�"+NOR+"������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
    "force" : 380,
    "lvl" : 88,
    "skill_name" : HIB "����ɷ�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+GRN+"����տ�"+NOR+"����ȭ���������֣��������ޣ�����������$n�ĵ���",
    "force" : 460,
    "lvl" : 100,
    "skill_name" : GRN "����տ�" NOR,
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int practice_level(){   return 100;  }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ǧҶ�ֱ�����֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�ѧ����ǧҶ�֡�\n");
if (me->query_skill("hand", 1) <=me->query_skill("qianye-shou", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ����ǧҶ�֡�\n");

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
    level   = (int) me->query_skill("qianye-shou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ǧҶ�ֱ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�����������������ǧҶ�֡�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
