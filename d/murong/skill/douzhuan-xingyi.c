// douzhuan-xingyi ��ת����
// 1997-2-14
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
YEL"�����һ��������������$nһ��һ����$n��������Խ����������һ��"NOR,
BLU"$n����һ����������$l��$N����$n��$l������Ī��������ﻬ��һ��"NOR,
HIW"$n˫��ǰ̽����۴���$N�ұۣ��ұ�ʹ��$N��������$N���л�ȥ"NOR,
HIY"$n���ƶ�ת��$N����Ī�����������;ת�˷���ֱ���Լ�Ϯ��"NOR,
YEL"$n�����Ϲۣ�˫����Է��ཻ���ƣ�̸Ц�侹ʹ��$N�������գ�ʹ��$N��֪����Ǻ�"NOR,
BLU"$n����������$N�͹����ʹ������������$N�ĳ�����������$N��������������"NOR,
HIW"ֻ��$n����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$N��$l",NOR,
HIY"$n����Ʈ�������������ƶ�ת֮�䷴��$N����������$N��ȴ����$N��˼�������",
});

int valid_enable(string usage)
{
	return usage == "parry";
}

string query_parry_msg(object weapon)
{
	if (!weapon) return 0;
	if (weapon->query("skill_type") == "sword")
		return parry_msg[random(sizeof(parry_msg))] + "��\n";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧϰ��ת���Ʊ�����֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ��ת���ơ�\n");
        return 1;
}

int practice_skill(object me)
{
	return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�\n");
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}

