// dugu-jiujian.c ���¾Ž�
inherit SKILL;
string *parry_msg = ({
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ��"+MAG+"�����"+NOR+"��������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�"+YEL+"��������"+NOR+"����ͼ��ʹ$P���С�\n",
        "$nͻȻʹ��������ɷ罣���ġ�"+RED+"���ڤڤ"+NOR+"�������Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�\n",
        "ֻ��$n���˷���������Ʈ�磬�����һʽ��"+HIW+"��������"+NOR+"���������޶�����׽���ص�ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�"+HIR+"�������"+NOR+"����ɭɭ�����������ܣ��ܿ���$P������\n",
});
string *parry_msg2 = ({
        "$n�������ܣ��ٽ������ʹ����"+BLU+"���両��"+NOR+"������$P��$l��\n",
        "ȴ��$n̤ǰһ������ʽбָ$N���ұۣ���Ҫʹ$N������ˡ�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬��æ���ֻط���\n",
        "$nͦ��һ�����ǡ�"+HIW+"���Ƴ��"+NOR+"���ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
});

mapping *action = ({
([  "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�"+HIC+"������Ȫ"+NOR+"��ֱ��$n��$l��",
    "force" : 10,
    "dodge" : -5,
    "damage": 30,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$N������$n�ӳ���"+RED+"Ȫ��ܽ��"+NOR+"������"+YEL+"�����ϸ�"+NOR+"������"+BLU+"ʯ������"+NOR+"������"+MAG+"��������"+NOR+"��\n����"+YEL+"���ף��"+NOR+"����ɽ���񽣣�",
    "force" : 10,
    "dodge" : -10,
    "damage": 30,
    "lvl" : 7,
    "damage_type" : "����"
]),
([
    "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ��"+MAG+"��Ůʮ�Ž�"+NOR+"�������������ʮ��\n������һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
    "force" : 10,
    "dodge" : -5,
    "damage": 40,
    "lvl" : 14,
    "damage_type" : "����"
]),
([  "action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ��",
    "force" : 20,
    "dodge" : -15,
    "damage": 40,
    "lvl" : 21,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ\n���ƻ���$n��$l��",
    "force" : 20,
    "dodge" : -20,
    "damage": 50,
    "lvl" : 28,
    "damage_type" : "����"
]),
([  "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������"+HIG+"̩ɽʮ����"+NOR+"��\nΪһ������$n��",
    "force" : 30,
    "dodge" : -25,
    "damage": 55,
    "lvl" : 35,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ�䣬ʹ����ɽ�ġ�"+HIC+"һ�������"+NOR+"��������$n��$l����֪������;��ͻȻת\n�򣬴��$n����֮�⣡",
    "force" : 40,
    "dodge" : -35,
    "damage": 60,
    "lvl" : 42,
    "damage_type" : "����"
]),
([  "action" : "$N����������һ�����ǡ�"+WHT+"������ɽ"+NOR+"��������$w����ն�䣬ֱ����$n��$l��",
    "force" : 50,
    "dodge" : -40,
    "damage": 80,
    "lvl" : 49,
    "damage_type" : "����"
]),
([  "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ�"+MAG+"�ٱ�ǧ������ʮ��ʽ"+NOR+"������ʽ������\n����ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
    "force" : 60,
    "dodge" : -45,
    "damage": 70,
    "lvl" : 56,
    "damage_type" : "����"
]),
([  "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n��",
    "force" : 70,
    "dodge" : -50,
    "damage": 90,
    "lvl" : 63,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ������\n����$n��",
    "force" : 80,
    "dodge" : -60,
    "damage": 80,
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ�����Ľ���\n��¶���ţ�",
    "force" : 90,
    "dodge" : -65,
    "damage": 90,
    "lvl" : 77,
    "damage_type" : "����"
]),
([  "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱��"+BLU+"���ѵ�ˮ"+NOR+"����һ�У�",
    "force" : 100,
    "dodge" : -70,
    "damage": 60,
    "lvl" : 84,
    "damage_type" : "����"
]),
([  "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������Ƿ�ħ��\n�ġ�"+RED+"����ʽ"+NOR+"����",
    "force" : 120,
    "dodge" : -75,
    "damage": 95,
    "lvl" : 91,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻ�˽����һ�ֹ���ġ�"+YEL+"�����罣��"+NOR+"������Ȼ��$n�����Ҵ�������",
    "force" : 140,
    "dodge" : -80,
    "damage": 120,
    "lvl" : 98,
    "damage_type" : "����"
]),
([  "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ��",
    "force" : 160,
    "dodge" : -90,
    "damage": 50,
    "lvl" : 105,
    "damage_type" : "����"
]),
([  "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô������",
    "force" : 180,
    "dodge" : -95,
    "damage": 80,
    "lvl" : 112,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻã�",
    "force" : 200,
    "dodge" : -100,
    "damage": 85,
    "lvl" : 119,
    "damage_type" : "����"
]),
([  "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò��أ�",
    "force" : 220,
    "dodge" : -110,
    "damage": 100,
    "lvl" : 126,
    "damage_type" : "����"
]),
([  "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ���\n�������ƣ�",
    "force" : 240,
    "dodge" : -115,
    "damage": 120,
    "lvl" : 133,
    "damage_type" : "����"
]),
([  "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ��",
    "force" : 260,
    "dodge" : -120,
    "damage": 100,
    "lvl" : 140,
    "damage_type" : "����"
]),
([  "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼�飡",
    "force" : 280,
    "dodge" : -130,
    "damage": 60,
    "lvl" : 147,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l��",
    "force" : 300,
    "dodge" : -150,
    "damage": 120,
    "lvl" : 154,
    "damage_type" : "����"
]),
([
    "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
    "force" : 400,
    "dodge" : -160,
    "damage": 165,
    "lvl" : 180,
    "damage_type" : "����"
])
});

int valid_enable(string usage)
{
    return (usage == "sword") || (usage == "parry");
}
string query_parry_msg(object me,object weapon)
{
    object my_weapon;

    if (!(my_weapon=me->query_temp("weapon"))){
    	if (!(my_weapon=me->query_temp("secondary_weapon")))
		  return "";
     }else{
	    if (!valid_enable(my_weapon->query("skill_type"))){
    		if (!(my_weapon=me->query_temp("secondary_weapon")))
				  return "";
			else			
			    if (!valid_enable(my_weapon->query("skill_type")))
				  return "";
	    }
	}
    if (weapon)
    	return parry_msg[random(sizeof(parry_msg))];
	else
	    return parry_msg2[random(sizeof(parry_msg2))];
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="feng qingyang")
        return notify_fail("���¾Ž��Ƿ���������������ʦ�����������������ܽ��㣿\n");
    if ((int)me->query("max_neili") < 2000)
        return notify_fail("�������������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("dugu-jiujian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("dugu-jiujian",1) > 60)
        return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    return notify_fail("���¾Ž�ֻ��ͨ����"+RED+"�ܾ�ʽ"+NOR+"����������\n");
}
string perform_action_file(string action)
{
    return __DIR__"dugu-jiujian/" + action;
}
