// guangming-blade.c ��������
// by -wyz from 1999,3.30
inherit SKILL;
mapping *action = ({
([  "action" : "$N�ٿ�Խ������$w���ʶ�����һ�С�"+RED+"��������"+NOR+"�������滯��һ�����⣬��$n��$l��ȥ",
    "force" : 120,
    "damage_type" : "����"
]),
([  "action" : "$N���յ������һ����һ�С�"+BLU+"�������"+NOR+"����$wһ��һ�գ�ƽ�л���$n�ľ���",
    "force" : 130,
    "damage_type" : "����"
]),
([  "action" : "$N�ᵶ������һ�С�"+HIW+"��â����"+NOR+"��������$w��â���䣬ն��$n��$l",
    "force" : 140,
    "damage_type" : "����"
]),
([  "action" : "$N�鵶ת��һ�С�"+WHT+"��Ͷ����"+NOR+"�����ż�һ�㣬����$wһ�Σ����϶��»���һ�����磬ֱ����$n��$l",
    "force" : 160,
    "damage_type" : "����"
]),
([  "action" : "$N����$wһ����һ�С�"+CYN+"����׳��"+NOR+"��������$wһ�ᣬ����$n��$l",
    "force" : 180,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��һ�С�"+MAG+"���Ǵ���"+NOR+"��������������һ�㣬����$w����������$n��$l",
    "force" : 210,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"���ܲ���"+NOR+"����$w�����ź�������������$n��$l",
    "force" : 240,
    "damage_type" : "����"
]),
([  "action" : "$N������أ�����$wһ�С�"+HIB+"�����η�"+NOR+"�����������꣬��$n��ȫ����ȥ",
    "force" : 280,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"ɽ��ˮ��"+NOR+"����$w���Ϻ�����$n��$l��ȥ",
    "force" : 320,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIY+"��������"+NOR+"����$w�����κ��·���ֱ����$n��$l",
    "force" : 320,
    "damage_type" : "����"
]),
([  "action" : "$N���ն��У�һ�С�"+RED+"��������"+NOR+"��������$w����������â������$n��$l",
    "force" : 350,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("blade", 1) < 20)
        return notify_fail("��Ļ����������̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("guangming-blade", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuhu-duanmendao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_duan")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
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
        return notify_fail("�����������������������\n");
    me->receive_damage("qi", 30);
    return 1;
}
//string perform_action_file(string action)
//{
//    return __DIR__"wuhu-duanmendao/" + action;
//}

