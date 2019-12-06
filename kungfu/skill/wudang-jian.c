//wudang-jian.c �䵱����
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "name":   "��������",
    "action" : "$N������ת�����ֽ�ָ��������ϥ����ǰ������������ǰ��һ�紦�̴ٶ���
����һ�С��������֡�������$w���������һ�����϶�������$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "������ˮ",
    "action" : "$N���β�������ǰ�������������ϱ������������󹭲���һ�С�������ˮ������
��$w��ǰ�·��̣�һ��ָ��$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 20,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���ֿ��",
    "action" : "$N�����ǰһ�����ŵ����������ڿռ�����ת������$w����ǰ�̣���ת���
��ʹ��һʽ�����ֿ�ѡ���������ƥ����й��$n��$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N�鲽�������ὣ�ؽ��������ϱ���һ�С��������š�ֱȡ$n��$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��Ů����",
    "action" : "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ����Ů���󡹣�
����������ת�������಻������$n��$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����ָ·",
    "action" : "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��һʽ
������ָ·������$n��$l",
    "force" : 120,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���б���",
    "action" : "$N�󳷲����������أ��ӽ���Բ���Σ���������������$wһʽ�����б��¡���
����Բ�󣬴���$n��$l",
    "force" : 110,
    "dodge" : 15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "������",
    "action" : "$N�����˲������ֽ�ָ��ת������һŤ���������������$wһ�ǡ���������
��������ָ��$n��$l",
    "force" : 150,
    "dodge" : 35,
    "damage" : 40,
    "lvl" : 0,
    "damage_type" : "����"
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 10)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("����ڹ����̫ǳ��\n");
    if ((int)me->query_skill("unarmed", 1) < 20)
   return notify_fail("��Ļ���ȭ�Ż��̫ǳ��\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("wudang-jian",1);
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
    if ((int)me->query("qi") < 20)
   return notify_fail("��������������䵱������\n");
    me->receive_damage("qi", 10);
    return 1;
}

