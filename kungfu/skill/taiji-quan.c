// taiji-quan.c ̫��ȭ
// ���Ӳ�ͬ���ܼ�����Ӧ��ѧϰ����ʹ����������, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
inherit SKILL;
mapping *action = ({
([  "action" : "$Nʹһ�С�"+YEL+"��ȸβ"+NOR+"����˫�ֻ��˸���Ȧ������$n��$l",
    "force" : 100,
    "skill_name" : YEL "��ȸβ" NOR,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С�"+RED+"����"+NOR+"���������������£���������ӳ�������$n��$l",
    "force" : 120,
    "skill_name" : RED "����" NOR,
    "lvl" : 5,
    "damage_type" : "����"
]),
([  "action" : "$N���ֻ��գ������ɹ����ƣ���������ʹһ�С�"+HIB+"������ʽ"+NOR+"������$n��$l��ȥ",
    "force" : 140,
    "skill_name" : HIB "������ʽ" NOR,
    "lvl" : 10,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ֻ������������ϣ��������£�ʹһ�С�"+WHT+"�׺�����"+NOR+"�����ֻ�$n�����ź�$l",
    "force" : 160,
    "skill_name" : WHT "�׺�����" NOR,
    "lvl" : 15,
    "damage_type" : "����"
]),
([  "action" : "$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ�С�"+HIR+"§ϥ�ֲ�"+NOR+"��������$n��$l",
    "force" : 180,
    "skill_name" : HIR "§ϥ�ֲ�" NOR,
    "lvl" : 20,
    "damage_type" : "����"
]),
([  "action" : "$N�������������������ںϣ�ʹһ�С�"+HIG+"�ֻ�����"+NOR+"������$n��$l��ȥ",
    "force" : 200,
    "skill_name" : HIG "�ֻ�����" NOR,
    "lvl" : 25,
    "damage_type" : "����"
]),
([  "action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ�С�"+HIY+"��׿���"+NOR+"��������$n��$l",
    "force" : 220,
    "skill_name" : HIY "��׿���" NOR,
    "lvl" : 30,
    "damage_type" : "����"
]),
([  "action" : "$N���ǰ̤�벽������ʹһ�С�"+HIB+"������"+NOR+"����ָ������$n��$l��ȥ",
    "force" : 240,
    "skill_name" : HIB "������" NOR,
    "lvl" : 35,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIM+"��ͨ��"+NOR+"�������һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
    "force" : 260,
    "skill_name" : HIM "��ͨ��" NOR,
    "lvl" : 40,
    "damage_type" : "����"
]),
([  "action" : "$N��������ԣ�ת�����������·ֱ�ӳ�������ʹһ�С�"+HIC+"б��ʽ"+NOR+"��������$n��$l",
    "force" : 280,
    "skill_name" : HIC "б��ʽ" NOR,
    "lvl" : 45,
    "damage_type" : "����"
]),
([  "action" : "$N�����鰴������ʹһ�С�"+HIW+"��������"+NOR+"������$n��$l��ȥ",
    "force" : 300,
    "skill_name" : HIW "��������" NOR,
    "lvl" : 50,
    "damage_type" : "����"
]),
([  "action" : "$N˫����ȭ����ǰ��󻮻���һ�С�"+BLK+"˫����"+NOR+"������$n��$l",
    "force" : 320,
    "skill_name" : BLK "˫����" NOR,
    "lvl" : 55,
    "damage_type" : "����"
]),
([  "action" : "$N�����黮������һ�ǡ�"+RED+"���ɴ�"+NOR+"������$n���ɲ�",
    "force" : 340,
    "skill_name" : RED "ָ�ɴ�" NOR,
    "lvl" : 60,
    "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+GRN+"����ʽ"+NOR+"�������ֻ���$n��$l�����ֹ���$n���ɲ�",
    "force" : 360,
    "skill_name" : GRN "����ʽ" NOR,
    "lvl" : 65,
    "damage_type" : "����"
]),
([  "action" : "$N�ɱ۴��֣�����ǰ����������ʹһ�С�"+YEL+"����"+NOR+"��������$n��$l",
    "force" : 380,
    "skill_name" : YEL "����" NOR,
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$N������������ʹһ�С�"+BLU+"�𼦶���"+NOR+"������$n��$l��ȥ",
    "force" : 400,
    "skill_name" : BLU "�𼦶���" NOR,
    "lvl" : 75,
    "damage_type" : "����"
]),
([  "action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ�С�"+MAG+"��̽��"+NOR+"��",
    "force" : 420,
    "skill_name" : MAG "��̽��" NOR,
    "lvl" : 80,
    "damage_type" : "����"
]),
([  "action" : "$N����ʹһʽ�С�"+CYN+"��Ů����"+NOR+"����������$n��$l��ȥ",
    "force" : 440,
    "skill_name" : CYN "��Ů����" NOR,
    "lvl" : 85,
    "damage_type" : "����"
]),
([  "action" : "$N���־���ǰ��������ǰƲ����ʹһ�С�"+WHT+"����Ʋ��"+NOR+"������$n��$l��ȥ",
    "force" : 460,
    "skill_name" : WHT "����Ʋ��" NOR,
    "lvl" : 90,
    "damage_type" : "����"
]),
([  "action" : "$N�����鰴������ʹһ�С�"+HIR+"ת�����"+NOR+"������$n��$l��ȥ",
    "force" : 480,
    "skill_name" : HIR "�������" NOR,
    "lvl" : 95,
    "damage_type" : "����"
]),
([  "action" : "$N�������ϻ�������������ʹһ�С�"+HIG+"������"+NOR+"������$n��$l��ȥ",
    "force" : 500,
    "skill_name" : HIG "��������" NOR,
    "lvl" : 100,
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С�"+HIY+"�Դ�"+NOR+"��������§��ϥ���������´���$n��$l",
    "force" : 520,
    "skill_name" : HIY "�Դ�" NOR,
    "lvl" : 110,
    "damage_type" : "����"
]),
([  "action" : "$N˫���ȱ�����״�����طֿ������������£�һ�С�"+HIB+"Ұ�����"+NOR+"������$n��$l�����Ŵ�ȥ",
    "force" : 480,
    "skill_name" : HIB "Ұ�����" NOR,
    "lvl" : 120,
    "damage_type" : "����"
]),
([  "action" : "$N��������ǰ���£��ұ�΢����ʹһ�С�"+HIM+"������ɽ"+NOR+"������$n��$l��ȥ",
    "force" : 500,
    "skill_name" : HIM "������ɽ" NOR,
    "lvl" : 130,
    "damage_type" : "����"
]),
([  "action" : "$N˫�־��¸�����������ǰ����ʮ��״��һʽ��"+HIC+"ʮ����"+NOR+"������$n��$l��ȥ",
    "force" : 520,
    "skill_name" : HIC "ʮ����" NOR,
    "lvl" : 140,
    "damage_type" : "����"
]),
([  "action" : "$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ�С�"+HIW+"��������"+NOR+"������$n��$l��ȥ",
    "force" : 540,
    "skill_name" : HIW "��������" NOR,
    "lvl" : 150,
    "damage_type" : "����"
]),
([  "action" : "$N��������ڳ���������ֱ���ұ�΢����ʹһ�С�"+BLK+"�����"+NOR+"������$n��$l�����Ŵ�ȥ",
    "force" : 560,
    "skill_name" : BLK "�����" NOR,
    "lvl" : 160,
    "damage_type" : "����"
]),
([  "action" : "$N˫���쿪������Ϊ�ᣬ����������һ����Բ����\nһ�С�"+RED+"ת�����"+NOR+"������$n�������¶�������������Ӱ֮��",
    "force" : 580,
    "skill_name" : RED "ת�����" NOR,
    "lvl" : 170,
    "damage_type" : "����"
]),
([  "action" : "$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���\nȭ�������һ�С�"+GRN+"�乭�仢"+NOR+"����ֱ��$n���Ѷ�ȥ",
    "force" : 600,
    "skill_name" : GRN "�乭�仢" NOR,
    "lvl" : 180,
    "damage_type" : "����"
]),
([  "action" : "$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ�С�"+YEL+"����Ʊ�"+NOR+"����һ�ɾ���ֱ��$n",
    "force" : 620,
    "skill_name" : YEL "����Ʊ�" NOR,
    "lvl" : 200,
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��̫��ȭ������֡�\n");
    if ((int)me->query_skill("taiji-shengong", 1) <= me->query_skill("taiji-quan", 1))
        return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���̫��ȭ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("taiji-quan", 1))
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
    level   = (int) me->query_skill("taiji-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/2;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��̫��ȭ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������̫��ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"taiji-quan/" + action;
}
