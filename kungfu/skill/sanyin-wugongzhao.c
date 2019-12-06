//sanyin-wugongzhao.c �������ץ
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$Nצ����ף��ǽ�¡�����϶���˺��$n��$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 30,
    "damage_type" : "ץ��"
]),
([  "action" : "$N˫�ֺ������֣�צצ���Ȱ�ץ��$n��$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 45,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��צӰ�ݺ�����������$n��$lץ��",
    "force" : 180,
    "dodge" : 30,
    "damage": 55,
    "damage_type" : "ץ��"
]),
([  "action" : "$Nһ���ֽУ�һצ���ֱ��$n�������",
    "force" : 240,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("���������צ������֡�\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("�������̫�����޷����������צ��\n");
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
	level = (int) me->query_skill("sanyin-wugongzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
        int skill;

	skill = me->query_skill("jiuyin-baiguzhao",1);
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������צ��\n");
	me->receive_damage("qi", 30);
        me->add("neili", -20);
	return 1;
}
