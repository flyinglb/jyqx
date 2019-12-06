// �嶾����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ��"+HIG+"��������"+NOR+"����$w����һ����״����һ���ŹֵĽǶȻ���$n������",
	"force" : 120,
        "dodge" : -10,
	"damage" : 50,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N΢�˰벽������$wʹ��һʽ��"+HIR+"֩����˿"+NOR+"�����ֻ����й���$n��$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 80,
	"lvl" : 15,
	"skill_name" : "֩����˿",
	"damage_type" : "����"
]),
([	"action" : "$N�����趯$w��һ�С�"+HIW+"Ы�ӽ�β"+NOR+"���ӱ��󻮵����ߴ���$n��$l",
	"force" : 170,
        "dodge" : 5,
	"damage" : 95,
	"lvl" : 30,
	"skill_name" : "Ы�ӽ�β",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��"+HIB+"��򼴩ѥ"+NOR+"����$w��������������������⣬��$n��$l��ȥ",
	"force" : 190,
        "dodge" : 5,
	"damage" : 120,
	"lvl" : 45,
	"skill_name" : "��򼴩ѥ",
	"damage_type" : "����"
]),
([	"action" : "$N����š���������鱧��Բ��һʽ��"+HIY+"�������"+NOR+"����$w�й�ֱ��������$n���ؿ�",
	"force" : 240,
        "dodge" : 10,
	"damage" : 120,
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��"+HIM+"��ʥ����"+NOR+"����$w����������зֳ���Ю����֮����Ȼն��$n��$l",
	"force" : 280,
        "dodge" : 5,
	"damage" : 200,
	"lvl" : 75,
	"skill_name" : "��ʥ����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword" || usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ��������嶾������\n");
        if ((int)me->query("max_neili") < 150)
                 return notify_fail("�������������\n");
	if ((int)me->query_skill("wudu-shengong", 1)<50)
		return notify_fail("����嶾�񹦻�򲻹����޷�ѧϰ�嶾������\n");
	return 1;
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
	int i, level;

        level   = (int) me->query_skill("wudu-goufa",1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
		return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������嶾������\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������嶾������\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"wudu-goufa/" + action;
}
