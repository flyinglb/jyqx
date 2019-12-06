// yuxiao-jian.c ���｣��
// modified by Venus Oct.1997
// Made by deaner

inherit SKILL;

mapping *action = ({
([      "action" : "$N����������һ�С�Ӣ�������Ҷ��С���ƮȻ����$n��ǰ���漴����$w΢��
���⼲����$n��$l",
        "force" : 150,
        "dodge" : 20,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nб��һ����ʹ��һʽ����Ů�鳤ֻ�޶̡����ӽ��������һ��һ�̵Ĺ�Ӱ
ֱ��$n��$l",
        "force" : 175,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���Ȼ��ȥ��˼�项��$w��Ȼ���������̻ص������У��漴ת����Ȼ
��ȥ��$n��ʱ�Ÿо�����һ�ɾ��������Լ���$l",
        "force" : 200,
        "dodge" : 25,
        "damage" : 40,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N˫�־ٽ����죬һ�С�����Ⱥ�������塹��$w���������ף����϶�����
$n��ͷ­��ȥ",
        "force" : 225,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ�������һЦ������������$w���΢΢һЦ��$nֻ����һ����ȴ��
һ����Ӱ�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ�����֣���",
        "force" : 250,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���̤ʵ���ҽ���㣬һ�С�һ����ϳ�᡹��$w����һ�Ž�����Ʈ��
�����ر���$n��$l",
        "force" : 270,
        "dodge" : 5,
        "damage" : 55,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ū������项�������ḧ$w���漴�͵�һ����������ǰһ�ݣ�
ֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
        "force" : 290,
        "dodge" : 5,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N������ף���ɫ��Ȼ��һ�С�������Թ���˳�����$w�������Ʋ����ش���
$n��$l",
        "force" : 310,
        "dodge" : -5,
        "damage" : 70,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������棬һ�С��˽�������������������$wб���»�����$n΢����֣�����
�ɼ䣬ȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
        "force" : 330,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 80,
        "damage_type" : "����"
]),
([  "action" : "$N��Ȼ��¶΢Ц��һ�С���������Ц���ա�������$wһ����������Ž�������$n
����������·",
        "force" : 360,
        "dodge" : -5,
        "damage" : 100,
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ����$w��һ�С��������������项��$w����һ���������������ƣ�$n
ֻ���õ���ǰһ�ƣ�һ����͵ľ��������Լ�",
        "force" : 390,
        "dodge" : -5,
        "damage" : 120,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����΢��һ�С�������������ϡ�������$w����������һ����������ĺ�����
ɲ�Ǽ��ɳ��ʯ��$n����һ�Ž���������£�������֧����",
        "force" : 420,
        "dodge" : 15,
        "damage" : 150,
        "lvl" : 110,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 500) ||
        ((int)me->query_skill("bibo-shengong", 1) < 100) ||
        !(me->query("couple/have_couple")))
       return notify_fail("��ҩʦ˵��: ���｣����ֻ����Ե���㲻���������ˡ�\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("yuxiao-jian",1);
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
    if ((int)me->query("qi") < 50)
       return notify_fail("����������������｣����\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"yuxiao-jian/" + action;
}
