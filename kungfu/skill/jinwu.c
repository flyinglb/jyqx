// jinwu-dao.c ���ڵ�
inherit SKILL;
mapping *action = ({
([  "action" : "$N�ص����գ�һ�С�"+RED+"����鮵�"+NOR+"�����������¶��ϻ��˸��뻡����$n��$l��ȥ",
    "force" : 120,
        "dodge" : -10,
        "parry" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : RED "����鮵�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�����������⣬һ�С�"+YEL+"÷ѩ����"+NOR+"��������$w��ֱ����$n��$l",
    "force" : 130,
        "dodge" : -10,
        "parry" : 10,
    "damage": 20,
    "lvl" : 12,
    "skill_name" : YEL "÷ѩ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+BLU+"ǧ��ѹ��"+NOR+"����$w�ƾ�������ˢ��һ�����϶�����$n����",
    "force" : 140,
        "dodge" : -5,
        "parry" : 5,
    "damage": 25,
    "lvl" : 18,
    "skill_name" : BLU "ǧ��ѹ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N���ַ�ִ������һ�С�"+HIW+"���ս��"+NOR+"������һ����$wֱ��$n�ľ���նȥ",
    "force" : 160,
        "dodge" : 5,
        "parry" : 5,
    "damage": 30,
    "lvl" : 24,
    "skill_name" : HIW "���ս��" NOR,
    "damage_type" : "����",
]),
([  "action" : "$Nһ�С�"+RED+"��������"+NOR+"�����������⻯����㷱�ǣ���$n��$l��ȥ",
    "force" : 180,
        "dodge" : 10,
        "parry" : 5,
    "damage": 35,
    "lvl" : 30,
    "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ֺ�ִ$w��һ�С�"+BLU+"����֮��"+NOR+"����š��ת������ֱ����$n��˫��",
    "force" : 210,
        "dodge" : 15,
        "parry" : 15,
    "damage": 40,
    "lvl" : 36,
    "skill_name" : BLU "����֮��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"���ò��"+NOR+"��������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
    "force" : 240,
        "dodge" : 15,
        "parry" : 15,
    "damage": 50,
    "lvl" : 42,
    "skill_name" : HIW "���ò��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N��ת�����׼�Լ���һ�С�"+RED+"������֦"+NOR+"����ȫ��һ��������$w��$n����նȥ",
    "force" : 280,
        "dodge" : 20,
        "parry" : 10,
    "damage": 60,
    "lvl" : 48,
    "skill_name" : RED "������֦" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+GRN+"��������"+NOR+"����$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
    "force" : 320,
        "dodge" : 10,
        "parry" : 20,
    "damage": 75,
    "lvl" : 54,
    "skill_name" : GRN "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����ƽָ��һ�С�"+YEL+"�󺣳�ɳ"+NOR+"����һƬƬ�йǵ�����쫷�����$n��ȫ��",
    "force" : 370,
        "dodge" : 5,
        "parry" : 25,
    "damage": 90,
    "lvl" : 60,
    "skill_name" : YEL "�󺣳�ɳ" NOR,
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("blade", 1) <=me->query_skill("jinwu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
int zhaoshu, level;
zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("jinwu",1);
if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������ڵ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
