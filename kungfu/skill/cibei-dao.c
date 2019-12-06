// cibei-dao.c �ȱ���
inherit SKILL;
mapping *action = ({
([  "action" : "$N����$wбָ��һ�С�"+YEL+"ͣ����·"+NOR+"��������һ�٣�һ����$n��$l��ȥ",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "ͣ����·" NOR, 
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+BLU+"ͯ�ӹһ�"+NOR+"������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
    "force" : 130,
    "lvl" : 8,
    "skill_name" : BLU "ͯ�ӹһ�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nչ���鲽������Ծ�䣬һ�С�"+WHT+"�ƴ�����"+NOR+"��������һ������ն��$n",
    "force" : 140,
    "lvl" : 16,
    "skill_name" : WHT "�ƴ�����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIM+"���ż�ɽ"+NOR+"����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
    "force" : 160,
    "lvl" : 24,
    "skill_name" : HIM "���ż�ɽ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����$wһ����һ�С�"+HIY+"��Ϫ����"+NOR+"����˫�ֳ����������У�����$n���ؿ�",
    "force" : 180,
    "lvl" : 33,
    "skill_name" : HIY "��Ϫ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��һ�С�"+YEL+"�Ź�����"+NOR+"�����������ã����ҿ�����������$n",
    "force" : 210,
    "lvl" : 42,
    "skill_name" : YEL "�Ź�����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"��������"+NOR+"�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
    "force" : 240,
    "lvl" : 51,
    "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����פ�أ�һ�С�"+BLU+"������Ϣ"+NOR+"�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
    "force" : 280,
    "lvl" : 60,
    "skill_name" : BLU "ͣ����·" NOR,
    "damage_type" : "����"
]),
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="fumo-jian"; }
int valid_learn(object me)
{
    object weapon;
    if ( !objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��������Ұѵ�����ѧ�ȱ�����\n");

    if ((int)me->query("max_neili") < 150)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�ȱ�����\n");

    if (me->query_skill("blade", 1) <=me->query_skill("cibei-dao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    else
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
    level   = (int) me->query_skill("cibei-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                        break;
                   }
    a_action["dodge"]  = 0-me->query_skill("cibei-dao",1)/2;
    a_action["damage"] = me->query_skill("cibei-dao",1);
    a_action["damage"] = me->query_skill("cibei-dao")/3;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if ( !objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������ȱ�����\n");
    me->receive_damage("qi", 25);
    return 1;
}
