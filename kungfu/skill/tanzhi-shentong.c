// tanzhi.c ��ָ��ͨ
inherit SKILL;
mapping *action = ({
([  "action" : "$N��ָ���˸���Ȧ��һʽ��"+BLK+"�����ѵ�"+NOR+"�����϶��»���$n��ȫ��",
    "force" : 320,
    "lvl" : 0,
    "skill_name" : BLK "�����ѵ�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N���ƻ��أ�һ�С�"+RED+"��������"+NOR+"������ָ��������ָ��$n�Ķ�ͷ",
    "force" : 280,
    "lvl" : 0,
    "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�������һʽ��"+GRN+"ǧ����ָ"+NOR+"������ָ��$n��$l",
    "force" : 190,
    "lvl" : 0,
    "skill_name" : GRN "ǧ����ָ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����һ̾��һ�С�"+YEL+"��ָ����"+NOR+"����˫�ֻó�����ָӰ������$n��$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : YEL "��ָ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIC+"Цָ����"+NOR+"����������ʽ����ָ����һ��ָ�����$n��$l",
    "force" : 240,
    "lvl" : 10,
    "skill_name" : HIC "Цָ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�ó���"+HIW+"����һָ"+NOR+"�����ȫ��������һָ����$n��$l",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIW "����һָ" NOR,
    "damage_type" : "����"
]),
});
  int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 80;  }
int valid_combine(string combo) { return combo=="lanhua-shuo"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ָ��ͨ������֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
    if (me->query_skill("finger", 1) <=me->query_skill("tanzhi-shentong", 1))
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
    level   = (int) me->query_skill("tanzhi-shentong", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level*2;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ָ��ͨ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("���������������Ϣһ�������ɡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("���������������ָ��ͨ��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tanzhi-shentong/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_str()*2) > victim->query_str() && me->query("neili")>100) {
        me->add("neili",-100);
        victim->receive_wound("qi", (damage_bonus) / 5 , me);
        return RED "˿˿һ�����죬�����������ǹ��ѵ�������\n" NOR;
    }
}
