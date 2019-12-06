// luohan-quan.c �޺�ȭ
inherit SKILL;
mapping *action = ({
([  "action" : "$N�����ϲ���һʽ��"+YEL+"��ݺ���"+NOR+"���������ַֿ�����ȭΪ�ƣ�����$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "��ݺ���" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�����̤��ȫ����ת��һ�С�"+RED+"���ﳯ��"+NOR+"���������͵ز���$n��$l",
    "force" : 200,
    "lvl" : 8,
    "skill_name" : RED "���ﳯ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С�"+MAG+"���Ӷ�Ӧ"+NOR+"����˫ȭ��$n��$l��ȥ",
    "force" : 220,
    "lvl" : 15,
    "skill_name" : MAG "���Ӷ�Ӧ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�"+WHT+"ƫ������"+NOR+"������$n��$l",
    "force" : 260,
    "lvl" : 24,
    "skill_name" : WHT "ƫ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С�"+HIB+"�ຣ��ͷ"+NOR+"��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
    "force" : 300,
    "lvl" : 33,
    "skill_name" : HIB "�ຣ��ͷ" NOR ,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ƻ�����һ�ǡ�"+GRN+"Юɽ����"+NOR+"�����Ƴ���磬һ�����е�$n������",
    "force" : 360,
    "lvl" : 42,
    "skill_name" : GRN "Юɽ����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+WHT+"������"+NOR+"����˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
    "force" : 420,
    "lvl" : 50,
    "skill_name" : WHT "������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����ڿۣ�����������һʽ��"+HIC+"�������"+NOR+"����˫�����밴��$n���ؿ�",
    "force" : 480,
    "lvl" : 58,
    "skill_name" : HIC "�������" NOR,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int practice_level(){   return 58;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("ѧ�޺�ȭ������֡�\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������̫�����޷����޺�ȭ��\n");
  if (me->query_skill("cuff", 1) <=me->query_skill("luohan-quan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�޺�ȭ��\n");
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
    level   = (int) me->query_skill("luohan-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���޺�ȭ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("��������������޺�ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}


