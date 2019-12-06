// chiqing-jian.c ������ʥ��
// Made by Robin

inherit SKILL;

mapping *action = ({
([      "action" : "$N����������һ�С�"WHT"��ң��·"NOR"����ƮȻ����$n��ǰ���漴����$w΢��
���⼲����$n��$l",
        "force" : 300,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nб��һ����ʹ��һʽ��"YEL"�鳤��Ů"NOR"�����ӽ��������һ��һ�̵Ĺ�Ӱ
ֱ��$n��$l",
        "force" : 350,
        "dodge" : 15,
        "damage" : 70,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�"HIM"ΡΡ����"NOR"����$w��Ȼ���������̻ص������У��漴ת����Ȼ
��ȥ��$n��ʱ�Ÿо�����һ�ɾ��������Լ���$l",
        "force" : 400,
        "dodge" : 25,
        "damage" : 80,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N˫�־ٽ����죬һ�С�"HIY"��뻪ɽ"NOR"����$w���������ף����϶�����
$n��ͷ­��ȥ",
        "force" : 450,
        "dodge" : 10,
        "damage" : 90,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ����"MAG"ǧ��һЦ"NOR"��������$w���΢΢һЦ��$nֻ����һ����ȴ��
һ����Ӱ�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ�����֣���",
        "force" : 500,
        "dodge" : 20,
        "damage" : 100,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���̤ʵ���ҽ���㣬һ�С�"CYN"�ٶ��ﳤ"NOR"����$w����һ�Ž�����Ʈ��
�����ر���$n��$l",
        "force" : 550,
        "dodge" : 5,
        "damage" : 110,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�"RED"����˼��"NOR"���������ḧ$w���漴�͵�һ����������ǰһ�ݣ�
ֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
        "force" : 590,
        "dodge" : 5,
        "damage" : 120,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N������ף���ɫ��Ȼ��һ�С�"GRN"�����黳"NOR"����$w�������Ʋ����ش���
$n��$l",
        "force" : 620,
        "dodge" : -5,
        "damage" : 140,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������棬һ�С�"HIW"ȵ������"NOR"��������$wб���»�����$n΢����֣�����
�ɼ䣬ȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
        "force" : 660,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 80,
        "damage_type" : "����"
]),
([  "action" : "$N��Ȼ��¶΢Ц��һ�С�"HIG"��������"NOR"��������$wһ����������Ž�������$n
����������·",
        "force" : 720,
        "dodge" : -5,
        "damage" : 180,
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ����$w��һ�С�"HIB"���Ӻ���"NOR"����$w����һ���������������ƣ�$n
ֻ���õ���ǰһ�ƣ�һ����͵ľ��������Լ�",
        "force" : 780,
        "dodge" : -5,
        "damage" : 200,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����΢��һ�С�"HIC"������½"NOR"��������$w����������һ����������ĺ�����
ɲ�Ǽ��ɳ��ʯ��$n����һ�Ž���������£�������֧����",
        "force" : 840,
        "dodge" : 15,
        "damage" : 220,
        "lvl" : 110,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 1000) ||
        ((int)me->query_skill("xuantian-force", 1) < 150))
       return notify_fail("�㹦���������޷�ѧϰ������ʥ����\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("chiqing-jian",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
       return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 80)
       return notify_fail("�������������������ʥ����\n");
    me->receive_damage("qi", 50);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"chiqing-jian/" + action;
}
