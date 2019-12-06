// jinshe-zhui.c

inherit SKILL;

mapping *action = ({
        ([      "name":		"ǧ����",
                "action":"$N˫��һ�Σ�һ�С�ǧ���򻯡������е�$w�ó������⣬
��һ�����������$n��$l",
                "dodge":	-20,
                "force":	200,
                "damage":	300,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "name":		"���Ī��",
                "action":"$N����һ����һ�����ð����ֻһɲ�Ǽ䣬����$wѸ�װ�Խ
�����ֵ�$w������һ�С����Ī�⡹�����ȷ���$n��$l",
                "dodge":	-40,
                "force":	300,
                "damage":	400,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

	if( (int)me->query_skill("jinshe-zhui",1) < 200 )
		return notify_fail("����׶��Ҫ200�����ϲ���������\n");
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취������׶����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ��������������׶����\n");

//	return notify_fail("����׶��û�����ڡ�\n");
	return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 500 )
                return 
notify_fail("�����������������û�а취��ϰ����׶����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
        write("�㰴����ѧ����һ�����׶����\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
 
