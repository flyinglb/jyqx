// taiji-jian.c ̫����
// cleansword 2/15/96
// Marz 5/21/96
inherit SKILL;
mapping *action = ({
([  "action" : "$N�鲽������һ�С�"+HIM+"���ѵ�ˮ"+NOR+"��������$w���������һ��������$n��$l",
    "force" : 60,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��"+YEL+"ָ����"+NOR+"��ֱ��$n��$l",
    "force" : 70,
    "lvl" : 10,
    "damage_type" : "����"
]),
([  "action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ��"+WHT+"�����"+NOR+"������$n��$l",
    "force" : 80,
    "lvl" : 15,
    "damage_type" : "����"
]),
([  "action" : "$N˫ϥ�³�������$wʹ��һʽ��"+BLU+"̽��ʽ"+NOR+"�������¶��ϼ���$n��$l",
    "force" : 90,
    "lvl" : 26,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"�����Ӳ�"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 100,
    "lvl" : 37,
    "damage_type" : "����"
]),
([  "action" : "$N���������һš��һ�С�"+BLK+"������β"+NOR+"��������$w������$n��$l��ȥ",
    "force" : 110,
    "lvl" : 48,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"��"+NOR+"��ɨ����һ�С�"+RED+"��"+NOR+"��ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
    "force" : 120,
    "lvl" : 50,
    "damage_type" : "����"
]),
([  "action" : "$N������ϥ������$wбָ��һ�С�"+HIC+"����Ͷ��"+NOR+"������$n��$l",
    "force" : 130,
    "lvl" : 60,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+CYN+"������ˮ"+NOR+"����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
    "force" : 140,
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����"+RED+"��"+NOR+"����"+HIW+"��"+NOR+"����$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
    "force" : 150,
    "lvl" : 80,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+MAG+"����Ҷ"+NOR+"����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
    "force" : 160,
    "lvl" : 100,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"����ͷ"+NOR+"����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
    "force" : 170,
    "lvl" : 120,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����"+HIR+"ʨ��ҡͷ"+NOR+"����$w�������󻮳�һ�����֣���$nȦ������",
    "force" : 180,
    "lvl" : 141,
    "damage_type" : "����"
]),
([  "action" : "$N���̤ʵ���ҽ���㣬һ�С�"+HIW+"����ָ·"+NOR+"��������$w����һ�Ž���������$n��$l",
    "force" : 190,
    "lvl" : 162,
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ��һ�С�"+CYN+"Ұ������"+NOR+"����$w�ڰ���л�ΪһȦ��â������$n��$l",
    "force" : 200,
    "lvl" : 184,
    "damage_type" : "����"
]),
([  "action" : "$N����ǰ���󹭣�һ�С�"+HIR+"����ʽ"+NOR+"��������$wֱ��$n��$l",
    "force" : 210,
    "lvl" : 205,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"С����"+NOR+"������������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ",
    "force" : 220,
    "lvl" : 226,
    "damage_type" : "����"
]),
([  "action" : "$N������ϣ�һ�С�"+HIW+"��Գ�׹�"+NOR+"��������$wбб����$n��$l��ȥ",
    "force" : 230,
    "lvl" : 248,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"ӭ�絧��"+NOR+"����$w���������һ�ӣ�$nȴ����һ�ɾ���ӭ��Ϯ����",
    "force" : 240,
    "lvl" : 260,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"˳ˮ����"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��",
    "force" : 250,
    "lvl" : 281,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"���Ǹ���"+NOR+"����$w����$n��$l",
    "force" : 260,
    "lvl" : 300,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻ�̶���������һ�С�"+BLU+"��������"+NOR+"����$w���¶��ϵ���$n��$l��ȥ",
    "force" : 270,
    "lvl" : 325,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIG+"����ʽ"+NOR+"����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 280,
    "lvl" : 346,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"�Ʒ��붴"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 290,
    "lvl" : 367,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"����չ��"+NOR+"��������Ծ������$w����$n��$l",
    "force" : 300,
    "lvl" : 380,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+BLK+"���ֽ�"+NOR+"����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
    "force" : 310,
    "lvl" : 390,
    "damage_type" : "����"
]),
([  "action" : "$N��������棬������ǰһ�ˣ�һ�С�"+BLU+"�����п�"+NOR+"����$w��$n��$l��ȥ",
    "force" : 320,
    "lvl" : 400,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"��ɨ÷��"+NOR+"��������Ծ�ڰ�գ�����$wɨ��$n��$l",
    "force" : 330,
    "lvl" : 410,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"ȴ���齣"+NOR+"�������Ծ����أ�$w�س飬���ֹ���$n��$l",
    "force" : 340,
    "lvl" : 430,
    "damage_type" : "����"
]),
([  "action" : "$N���Ȱ�����ף�һ�С�"+WHT+"����Ʊ�"+NOR+"����������ָ��ת������$n��$l",
    "force" : 350,
    "lvl" : 440,
    "damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��һ�С�"+HIY+"����հ��"+NOR+"����$w�й�ֱ��������$n��$l",
    "force" : 380,
    "lvl" : 450,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int practice_level(){   return 145;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧ̫��������\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 60 )
        return notify_fail("���̫���񹦻��̫ǳ��\n");
    if ((int)me->query_skill("taiji-quan", 1) <= me->query_skill("taiji-jian", 1))
    if ((int)me->query_skill("taiji-quan", 1) < 100 )
        return notify_fail("���̫��ȭ���̫ǳ��\n");
    if (me->query_skill("sword", 1) <=me->query_skill("taiji-jian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("taiji-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
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
        return notify_fail("�������������̫��������\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"taiji-jian/" + action;
}
