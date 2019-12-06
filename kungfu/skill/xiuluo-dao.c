// xiuluo-dao.c ���޵�
inherit SKILL;
mapping *action = ({
([  "action" : "$N�ص����գ�һ�С�"+YEL+"������ӥ"+NOR+"�����������¶��ϻ��˸��뻡����$n��$l��ȥ",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "������ӥ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�����������⣬һ�С�"+RED+"Ͷ�����"+NOR+"��������$w��ֱ����$n��$l",
    "force" : 130,
    "lvl" : 12,
    "skill_name" : RED "Ͷ�����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+BLU+"�ͷл��"+NOR+"����$w�ƾ�������ˢ��һ�����϶�����$n����",
    "force" : 140,
    "lvl" : 18,
    "skill_name" : BLU "�ͷл��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N���ַ�ִ������һ�С�"+HIC+"�۹ǳ���"+NOR+"������һ����$wֱ��$n�ľ���նȥ",
    "force" : 160,
    "lvl" : 24,
    "skill_name" : HIC "�۹ǳ���" NOR,
    "damage_type" : "����",
]),
([  "action" : "$Nһ�С�"+HIW+"����ǧ��"+NOR+"�����������⻯����㷱�ǣ���$n��$l��ȥ",
    "force" : 180,
    "lvl" : 30,
    "skill_name" : HIW "����ǧ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ֺ�ִ$w��һ�С�"+RED+"���۲�ʩ"+NOR+"����š��ת������ֱ����$n��˫��",
    "force" : 210,
    "lvl" : 36,
    "skill_name" : RED "���۲�ʩ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"��Ƥ�龭"+NOR+"��������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
    "force" : 240,
    "lvl" : 42,
    "skill_name" : RED "��Ƥ�龭" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N��ת�����׼�Լ���һ�С�"+HIB+"���ľ�־"+NOR+"����ȫ��һ��������$w��$n����նȥ",
    "force" : 280,
    "lvl" : 48,
    "skill_name" : HIB "���ľ�־" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIR+"������"+NOR+"����$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
    "force" : 320,
    "lvl" : 54,
    "skill_name" : HIR "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����ƽָ��һ�С�"+RED+"��Ѫ����"+NOR+"����һƬƬ�йǵ�����쫷�����$n��ȫ��",
    "force" : 370,
    "lvl" : 60,
    "skill_name" : RED "��Ѫ����" NOR,
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="damo-jian"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("�����Ҫ��Ū�ѵ�����\n");

    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������������\n");
    if (me->query_skill("blade", 1) <=me->query_skill("xiuluo-dao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ���޵���\n");
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
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("xiuluo-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������޵���\n");
    me->receive_damage("qi", 35);
    return 1;
}
