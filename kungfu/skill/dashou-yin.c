//
// dashou-yin.c ���ڴ���ӡ
//
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹ��һ�С�"+HIW+"��������ӡ"+NOR+"����˫�ƺ�ʮ��ֱֱײ��$n��ǰ��",
        "skill_name" : HIW "��������ӡ" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"���ƹ���ӡ"+NOR+"��������Ծ��˫���繴��ץ��$n��$l",
        "skill_name" : HIW "���ƹ���ӡ" NOR,
        "force" : 200,
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"׼���ĸӡ"+NOR+"����������ָ��ֱȡ$n��$l",
        "skill_name" : HIW "׼���ĸӡ" NOR,
        "force" : 250,
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"��������ӡ"+NOR+"����ŭ��һ����һ�Ƶ�ͷ����$n��$l",
        "skill_name" : HIW "��������ӡ" NOR,
        "force" : 300,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"ҩʦ�����ӡ"+NOR+"�����ͳ���ǰ�����������㹥��$n",
        "skill_name" : HIW "ҩʦ�����ӡ" NOR,
        "force" : 350,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"���½��ӡ"+NOR+"������������˫������ɨ��$n��$l",
        "skill_name" : HIW "���½��ӡ" NOR,
        "force" : 400,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"���ֽ��ӡ"+NOR+"���������Ծ��˫��ǰ�������ץ��$n���ʺ�",
        "skill_name" : HIW "���ֽ��ӡ" NOR,
        "force" : 450,
        "lvl" : 48,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"�����ǻ�ӡ"+NOR+"������ʱ��������������г���������Ӱ����$n��$l",
        "skill_name" : HIW "�����ǻ�ӡ" NOR,
        "force" : 500,
        "lvl" : 56,
        "damage_type" : "����",
]),
});
int practice_level(){   return 56;  }
int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_combine(string combo) { return combo=="yujiamu-quan"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����ڴ���ӡ������֡�\n");
    else if ((int)me->query("max_neili") < 150)
        return notify_fail("�������������\n");
      if (me->query_skill("hand", 1) <=me->query_skill("dashou-yin", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("longxiang", 1) >= 20 ||
        (int)me->query_skill("xiaowuxiang", 1) >= 20)
        return 1;
    else if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("���������������̫ǳ��\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("���С���๦���̫ǳ��\n");

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
          level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
			break;
		}
    a_action["dodge"]  = 0-me->query_skill("dashou-yin",1)/2;
    a_action["parry"]  = 0-me->query_skill("dashou-yin",1)/2;
    a_action["damage"] = me->query_skill("dashou-yin",1);
    return a_action;

}
int practice_skill(object me)
{
//    object weapon;
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����ڴ���ӡ������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("����������������������ڴ���ӡ��\n");
    me->receive_damage("qi", 20);
    return 1;
}
