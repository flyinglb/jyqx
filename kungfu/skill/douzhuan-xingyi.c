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
HIW"ֻ��$n����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$N��$l"NOR,
HIY"$n����Ʈ�������������ƶ�ת֮�䷴��$N����������$N��ȴ����$N��˼�������"NOR,
});

int valid_enable(string usage)
{
        return usage == "parry";
}

string query_parry_msg(object weapon)
{
	
		return parry_msg[random(sizeof(parry_msg))] + "��\n";
}

int valid_learn(object me)
{
//      object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "����Ľ��"|| myfam["master_id"] != "murong bo")
                return notify_fail("��ת����ֻ����Ľ�ݲ�ѧϰ��\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취����ת���ơ�\n");
        if( (int)me->query_skill("shenyuan-gong",1)<100)
                return notify_fail("�����Ԫ���ȼ�������\n");
        if ((int)me->query_skill("douzhuan-xingyi",1) > 150)
                return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�\n");

        return 1;
}

int practice_skill(object me)
{
        if(me->query_skill("douzhuan-xingyi",1)>80)
                return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�\n");
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}

