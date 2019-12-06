//qianzhu-wandushou ǧ������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N�������ֹŹ���ɫ�����϶���˺��$n��$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 30,
    "lvl" : 0,
    "skill_name" : "ǧɫ���" ,
    "damage_type" : "ץ��"
]),
([  "action" : "$N˫�ֺ������֣����й��Ȱ�����$n��$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 45,
    "lvl" : 30,
    "skill_name" : "ǧ������" ,
    "damage_type" : "����"
]),
([  "action" : "$N����Χ$nһת�����ֳ�ץ������$n��$lץ��",
    "force" : 180,
    "dodge" : 30,
    "damage": 55,
    "lvl" : 60,
    "skill_name" : "ǧ���Ӱ" ,
    "damage_type" : "ץ��"
]),
([  "action" : "$Nһ���ֽУ�����Ϊȭ��������ֱ��$n��С��",
    "force" : 240,
    "dodge" : 50,
    "skill_name" : "ǧ����" ,
    "damage": 100,
    "lvl"   : 100,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("��ǧ�����ֱ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
            return notify_fail("�������̫�����޷���ǧ�����֡�\n");
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
	int i, level;
	level = (int) me->query_skill("qianzhu-wandushou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
        int skill;

	skill = me->query_skill("qianzhu-wandushou",1);
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ǧ�����֡�\n");
	me->receive_damage("qi", 30);
        me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
    return __DIR__"qianzhu-wandushou/" + action;
}
