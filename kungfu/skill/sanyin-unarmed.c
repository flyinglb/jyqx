// sanyang-unarmed.c -������
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+GRN+"��ɽѩƮ"+NOR+"������Ӱ���裬��ʱ֮�佫$n�����Ѩ����ס��",
    "force" : 200,
    "lvl" : 0,
    "skill_name" : GRN "��ɽѩƮ" NOR,
        "damage_type" : "����"
]),
([  "action" : "�ں��������У�$Nʹһ�С�"+RED+"˫������"+NOR+"��������Ǳ����ˮ������������������������$n��$l",
    "force" : 250,
    "lvl"   : 40,
    "skill_name" : RED "˫������" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$N˫ȭ���裬һʽ��"+HIY+"��ת����"+NOR+"�������Ƽ��������һ����Ȧ��������ɫ����ƮƮ�ش���$n",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : HIY "��ת����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIG+"�����ɷ"+NOR+"������һ�һ��������$n�ȻƮȥ����$n��$l",
    "force" : 300,
    "lvl"   : 60,
    "skill_name" : HIG "�����ɷ" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"�˷�����"+NOR+"�����յ�Х�磬�������������Ƶ����ˣ�����$n�Ķ���",
    "force" : 260,
    "lvl"   : 80,
    "skill_name" : HIW "�˷�����" NOR ,     
    "damage_type" : "����"
]),
([  "action" : "$N������ɫ�ģ�һ�С�"+HIB+"�����л�"+NOR+"����ȴ�������������Ϣ�������",
    "force" : 300,
    "lvl"   : 150,
    "skill_name" : HIB "�����л�" NOR ,     
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 250)
        return notify_fail("�������̫�����޷��������ơ�\n");
    if ((int)me->query_skill("unarmed",1) <30)
        return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ѧ�����ơ�\n");
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
    level   = (int) me->query_skill("sanyin-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*2;
    return a_action;

}


int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("������������������ơ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"sanyin-unarmed/" + action;
}
