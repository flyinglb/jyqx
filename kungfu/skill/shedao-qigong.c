// shedao-qigong  �ߵ��湦
inherit SKILL;
mapping *action = ({
([  "action" : "$Nʹһ�С�"+HIC+"�ɺ�����"+NOR+"������$wһ�ᣬ����$n��$l",
    "force": 150,
    "damage_type" : "����",
    "skill_name" : HIC "�ɺ�����" NOR,
]),
([  "action": "$Nʹ����"+HIY+"���߳���"+NOR+"��������΢��,����$wٿ����$n��$l��ȥ",
    "force": 250,
    "damage_type": "����",
    "skill_name" : HIY "���߳���" NOR,
]),
([  "action": "$N����΢��,���㷴��,����ת��,ʹһ�С�"+HIM+"��������"+NOR+"��������$w�Ѵ���$n$l",
    "force": 250,
    "damage_type": "����",
    "skill_name" : HIM "��������" NOR,
]),
([  "action" : "$Nʹһʽ��"+HIY+"�������"+NOR+"����������$n, ����һ��,˳����$w��һ��,$w��Ȼ���Լ��ʺ���.����$N��������һ��,$w�ӹ����ʺ�,����$n�������",
    "lvl" : 40,
    "damage_type" : "����",
    "skill_name" : HIY "�������" NOR,
]),
([  "action": "$N�����ڵ���һ���,ʹһ�С�"+HIW+"С�����"+NOR+"��,��$n�������,����$wֱ��$n",
    "force": 350,
    "damage_type": "����",
    "skill_name" : HIW "С�����" NOR,
]),
([  "action": "$N���һ����ʹһ�С�"+HIR+"����ٶ�"+NOR+"������������$n��ȪҪѨ,����$nˤ���ڵ�",
    "force": 400,
    "damage_type": "����",
    "skill_name" : HIR "����ٶ�" NOR,
]),
([  "action": "$N˫��һ��,�������,һ�С�"+HIB+"³�ﲦ��"+NOR+"������ץ��$n�ҽ�����,����$wֱ��$nС��",
    "force": 400,
    "damage_type": "����",
    "skill_name" : HIB "³�ﲦ��" NOR,
]),
([  "action": "$NͻȻһ�������,һ�С�"+HIC+"���ཱུ��"+NOR+"��,˫��һ��,���ڼ�ͷ,˫��ֱ��$n",
    "force": 400,
    "damage_type": "����",
    "skill_name" : HIC "���ཱུ��" NOR,
]),
});
int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    object weapon;
    if (objectp(weapon = me->query_temp("weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
    if (objectp(weapon = me->query_temp("secondary_weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if (me->query_skill("sword", 1) <=me->query_skill("shedao-qigong", 1)
        && me->query_skill("staff", 1) <=me->query_skill("shedao-qigong", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
        return notify_fail("��������ķ���򲻹����޷�ѧ�ߵ��湦.\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�ߵ��湦��\n");
    if ((int)me->query_skill("shenlong-bashi", 1) < 50)
        return notify_fail("���������ʽ��򲻹����޷�ѧ�ߵ��湦��\n");
    if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
        return notify_fail("��������ķ���򲻹����޷�����ѧ�ߵ��湦��\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level;
    level   = (int) me->query_skill("shedao-qigong", 1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*3;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (objectp(weapon = me->query_temp("weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
    if (objectp(weapon = me->query_temp("secondary_weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 30)
        return notify_fail("��������������ߵ��湦��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"shedao-qigong/" + action;
}
