// yunv-jian.c ��Ů��

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�����б����������б�ɣ�����$w�������$n��$l",
        "force" : 60,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 35,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ���𣬡��׺羭�졹��$w��Ȼ�´�",
        "force" : 70,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 40,
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����˼����ġ����ӽ�ֱ���������ɵ�",
        "force" : 80,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 45,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ����ǰ���¡�һ�����϶��²�����ģ����ֺ�ա�����̵صĹ�
��",
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : "$N����$w���������ʻ���չ���ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪��
�ι���",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 55,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������С�á��������𣬽�����ָ�����������ƣ�ֱ��$n��
$l",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 60,
        "lvl" : 24,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��������һ�̣�������������ʹ����ɨѩ��衹��",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 65,
        "lvl" : 29,
        "damage_type" : "����"
]),
([      "action" : "$N���ƺ����ǰ��������$w����ӷ���ȴ��һ�С����ٰ�����",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 34,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����¶��ġ���$w���������һ���󻡣�����$n��$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 75,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$N����������ң�������Ϊ������$n��ȴ��һ�С��رߵ��ס�",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 80,
        "lvl" : 44,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������Ʈ����$w����ػ�������Բ������$n��$l��ȥ",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 85,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�С԰�վա�������$wѸ����$n��������������",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 90,
        "lvl" : 54,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������ҹ����������$w�й�ֱ�룬����$n��$l",
        "force" : 180,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 95,
        "lvl" : 59,
        "damage_type" : "����"
]),
([      "action" : "$N��������ҵͣ�һ�С��������䡹��$w�ڿ��л���һ���⻷������
$n",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 100,
        "lvl" : 64,
        "damage_type" : "����"
]),
([      "action" : "$N����$w���¶��Ͼ��������������һ�㣬ȴ�ǡ������ٳء�",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 105,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N������״��һ�С�ľ�����㡹������$wֱ��$n��$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 110,
        "lvl" : 76,
        "damage_type" : "����"
]),
([      "action" : "$N���ֽ���һ�죬����$wƽƽ����$n��$l����һ�С�˫���Իء�",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 115,
        "lvl" : 82,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�����̣�һ�С����Ƴ��ԡ���ֱָ$n��$l",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 120,
        "lvl" : 88,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������չȡ���$w���������һ�ӣ���$n����˼��ĽǶȹ���
",
        "force" : 240,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 125,
        "lvl" : 94,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����軨��·����һʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�
",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 130,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�İ·��ɣ����$w�������㣬����$n��$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 135,
        "lvl" : 99,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�̶�������һ�С�������������$w���¶��ϴ���$n",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 140,
        "lvl" : 106,
        "damage_type" : "����"
]),
([      "action" : "$N���Ų�������$wͻȻ���Լ������´̳���ȴ��һ�С����Ľ�����
",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 145,
        "lvl" : 112,
        "damage_type" : "����"
]),
([      "action" : "$N������ˮ�滬��һ�㣬һ�С�������ҹ����ƽƽ����$n��$l��ȥ",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 150,
        "lvl" : 118,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������������$w�̵�$n������",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 155,
        "lvl" : 124,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ĵ�����᡹��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 160,
        "lvl" : 131,
        "damage_type" : "����"
]),
([      "action" : "$N��������棬������ǰһ�ˣ�һ�С���ҩ���项��$w��$n��$l��
ȥ",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 165,
        "lvl" : 138,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ǰ���ࡹ������Ծ������$wɨ��$n��$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 165,
        "lvl" : 145,
        "damage_type" : "����"
]),

([  "action" : "$N������Ȼ֮ɫ������һ�С�����Բԡ���$w����$n��$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 175,
        "lvl" : 159,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15)
                return notify_fail("�����Ů�ķ���򲻵����޷�ѧϰ��Ů������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunv-jian",1);
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
        if ((int)me->query("qi") < 45)
                return notify_fail("���������������Ů������\n");
        if ((int)me->query("neili") < 15)
                return notify_fail("�����������������Ů������\n");
        me->receive_damage("qi", 26);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
