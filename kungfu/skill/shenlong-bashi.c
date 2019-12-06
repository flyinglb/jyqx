// shenlong-bashi ������ʽ
inherit SKILL;
mapping *action = ({
([  "action" : "$Nʹһ�С�"+HIW+"��Ӱ��б"+NOR+"��,��������һĨ����$n��$l��ȥ",
    "force": 100,
        "damage_type" : "����",
    "skill_name" : HIW "��Ӱ��б" NOR,
]),
([  "action" : "$N�������,˫��ʹһ�С�"+HIC+"�嶡��ɽ"+NOR+"��������$n��$l",
    "damage_type" : "����",
    "skill_name" : HIC "�嶡��ɽ" NOR,
]),
([  "action": "$N˳��ʹһ�С�"+RED+"���в���"+NOR+"�����Ƽ�ת��,���ƻ���,����ֱ��$n",
    "force": 200,
    "damage_type": "����",
    "skill_name" : RED "���в���" NOR,
]),
([  "action": "$N�˺󼸲�,ͻȻ����һ��,һ�С�"+YEL+"������β"+NOR+"�����ޱȹ���ػ���$n",
    "force": 250,
    "damage_type": "����",
    "skill_name" : YEL "������β" NOR,
]),
([  "action" : "$Nʹһʽ��"+HIC+"������"+NOR+"����ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
    "damage_type" : "����",
    "skill_name" : HIC "������" NOR,
]),
([  "action": "$N����ʹ����"+BLU+"Ǭ������"+NOR+"��,����֧��,˫�ȷ�������$n",
    "force": 250,
    "damage_type": "����",
    "skill_name" : BLU "Ǭ������" NOR,
]),
([  "action": "$N���һ����ʹ����"+GRN+"ͬ���ھ�"+NOR+"��������һ�а�����$n",
    "force": 400,
    "damage_type": "����",
    "skill_name" : GRN "ͬ���ھ�" NOR,
]),
([  "action": "$N����һ����,�����ǳ���״,��Ȼ���Ǹ��°�ֱײ��$n",
    "force": 400,
    "damage_type": "����",
    "skill_name" : "���Ǹ���"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��������ʽ������֡�\n");
    if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
        return notify_fail("��������ķ���򲻹����޷�ѧ������ʽ.\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ������ʽ��\n");
    if ((int)me->query("max_neili") < 350)
        return notify_fail("�������̫�����޷���������ʽ��\n");
    if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
        return notify_fail("��������ķ���򲻹����޷�����ѧ������ʽ��\n");
    if (me->query_skill("hand", 1) <=me->query_skill("shenlong-bashi", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level;
    level   = (int) me->query_skill("shenlong-bashi", 1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��������ʽ������֡�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 30)
        return notify_fail("�������������������ʽ��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
