// zhengliangyi-sword �����ǽ���
inherit SKILL;
mapping *action = ({
([  "action":"\n$Nʹһʽ��"+YEL+"���ɷ���"+NOR+"��������$w����Ӱ��ֱк��������$n��$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "���ɷ���" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N����ǰ��ʹ����"+MAG+"���ɻ�"+NOR+"�����ߵ�ȫ��б�ƣ�ʹ�㼫��׽����$w��������$n��$l��ȥ",
    "force" : 140,
    "lvl" : 8,
    "skill_name" : MAG "���ɻ�" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$Nһʽ��"+WHT+"ľҶ����"+NOR+"��������һ�������Ⱪ�ǣ�����$wңҡָ��$n��$l",
    "force" : 160,
    "lvl" : 15,
    "skill_name" : WHT "ľҶ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��������Ծ��һʽ��"+HIR+"��Įƽɳ"+NOR+"��������һ�ۣ�����$w������֮����������$nȫ��",
    "force" : 180,
    "lvl" : 20,
    "skill_name" : HIR "��Įƽɳ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w�й�ֱ����һʽ��"+BLU+"��÷����"+NOR+"����$w��Ȼ���䵯���������Բ���˼����ٶ�ֱ����$n��$l",
    "force" : 220,
    "lvl" : 30,
    "skill_name" : BLU "��÷����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һʽ��"+HIB+"ͬ����֦"+NOR+"����������ã�����˺�գ�����$n��$l",
    "force" : 250,
    "lvl" : 40,
    "skill_name" : HIB "ͬ����֦" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N��һʽ��"+WHT+"������ɫ"+NOR+"��������������罭�ӵ�к����â�����޾���$n��$l����",
    "force" : 280,
    "lvl" : 50,
    "skill_name" : WHT "������ɫ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��"+RED+"����һ���"+NOR+"������$n��$l",
    "force" : 320,
    "lvl" : 60,
    "skill_name" : RED "����һ���" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��һʽ��"+HIM+"�űڶ���"+NOR+"�������Ծ����л�����,$w����$n��$l",
    "force" : 380,
    "lvl" : 70,
    "skill_name" : HIM "�űڶ���" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N����һ���εض���һʽ��"+HIG+"�����¶"+NOR+"����������磬��Ӱ��ɽ����$n",
    "force" : 420,
    "lvl" : 110,
    "skill_name" : HIG "������ͬ��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N�������Ʈ�䣬һʽ��"+GRN+"��������"+NOR+"�������级�籼�ף�������У�ʽ���ʽ��ʹ$n��æ����",
    "force" : 450,
    "lvl" : 150,
    "skill_name" : GRN "��������" NOR,
    "damage_type":  "����"
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧ������\n");

    if (me->query_skill("sword", 1) <=me->query_skill("zhengliangyi-sword", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    level   = (int) me->query_skill("zhengliangyi-sword",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level*2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("������������������ǽ�����\n");
    me->receive_damage("qi", 25);
    return 1;
}
