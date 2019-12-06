// six-fingers.c ������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([ "name":   "���̽�",
           "action": "$N����������˫��Ĵָͬʱ����������������죬�����̽���
����ʯ���쾪���������֮�ƣ���ָ$n���к�$l",
           "force":  350,
           "dodge":  50,
           "damage": 500,
           "damage_type":  "����"
        ]),
        ([ "name":   "������",
           "action": "$Nʳָ����������԰ת������������һ����һ���Ĵ̳�������
Ѹ�٣����ɻ��ã������ݺᣬ$n�����޷�������·",
           "force":  400,
           "dodge":  100,
           "damage": 400,
           "damage_type":  "����"
        ]),
        ([ "name":   "�г彣",
           "action": "$N������ָһ�������г彣����ǰ�̳��������ĵ�����Ȼ���죬
���ν���ֱָ$n��$l",
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "����"
        ]),
        ([ "name":   "�س彣",
           "action": "$N��������ָ��������س彣����·׾�͹��ӣ�һ���ۻ����
���ĵ�����������ɽ��������$nӿȥ",
           "force":  350,
           "dodge":  60,
           "damage": 500,
           "damage_type":  "����"
        ]),
        ([ "name":   "����",
           "action": "$N����Сָһ�죬һ���������ٳ�Ѩ�м�������������󽣡�
������磬ָ��$n��$l",
           "force":  350,
           "dodge":  50,                            
           "damage": 500,
           "damage_type":  "����"
        ]),
        ([ "name":   "�ٳ彣",
           "action": "$N���ַ�ָ��Сָ������������ٳ�Ѩ���������������󽣡�
������䣬��$n���벻���ķ������$n��$l",
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "����"
        ]),
});


int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������񽣱�����֡�\n");
        if ((int)me->query("max_neili") < 1200)
            return notify_fail("�������̫�����޷�ѧ�����񽣡�\n");
        if ((int)me->query_skill("kurong-changong",1) < 120)
            return notify_fail("��Ŀ�������̫�ͣ��޷�ѧ�����񽣡�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        int skill;

        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("������������������񽣡�\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("�����书�����������¡�\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() )
	{
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
	}
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("six-finger",1)) > 60 &&
		me->query_skill("kurong-changong",1) > 60 &&
		me->query("neili") > 100)
	{
		me->add("neili", -100);
		return ([
	"action": "$N��Ȼ���ý����е���·����һһӿ����ͷ��ʮָ�׵�����ȥ������
�����޾��������ݺᣬ����������·������ת��ʹ��$n��ʱ������ң���
��ȫ������ʹ��������Ѫ�����ϱ������ʹ̧ͷһ����һ������ӭ���ֵ�",
	"damage": 500,
	"damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
      return __DIR__"six-finger/" + action;
}
