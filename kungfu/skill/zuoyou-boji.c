// zuoyou-boji.c -���Ҳ���֮��
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$NͻȻ��������ȭ����һ�٣��·�����ס��һ����$n���������ƣ�ȴͻ
Ȼ����һ��ȭͷ���ž�������Լ�������",
    "force" : 300,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "��ȭ����"
]),
([      "action" : "$N���κ�Ȼһ���������Ѿ����ƣ�б���Ϸ��˲��ϲ���ؼ���$n��С
��",
    "force" : 325,
    "dodge" : 55,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "�˲��ϲ�"
]),
([      "action" : "$N�����ȭ��������һ�ģ��漴ֱ��������ع���$n��ͷ��",      
    "force" : 350,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "ֱ������"
]),
([      "action" : "$NͻȻ������������Լ������⣬������ָ�ſ�������Ѹ�ٵػ���$n
����������������$n����������һ����ָɽ",
    "force" : 375,
    "dodge" : 45,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "��ָ��ɽ"
]),
([      "action" : "$N˫��һ�ģ��漴���ƹ���$n����磬$n��æ�мܣ�$N������ȴ�ѱ�
ȭ�͵ص���$n���ؿ�",
    "force" : 400,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl" : 40,
    "skill_name" : "��������"
]),
([      "action" : "$N�����£������ϵ�ǰ��һ�࣬�漴һ�������ƴ������ϻ������Ƴ�
һ������֮��Ϯ��$n���ؿ�",
    "force" : 425,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 50,
    "skill_name" : "���հ���"
]),
([      "action" : "$N˫������ǰһ��Ȼ�����ֱ�ȭ����$n��ͷ����$n�����ո񿪣�ȴ
����$N�������������Լ��������£����ɴ�",
    "force" : 450,
    "parry" : 20,
    "dodge" : 50,
    "damage_type" : "����",
    "lvl" : 60,
    "skill_name" : "ָ�ϴ�"
]),
([      "action" : "$N�����͵�ץס�Լ�����ۣ�������һת�����ѱ��ƣ����������ֵ�
������ǰ�����������$n��$l",
    "force" : 500,
    "parry" : 30,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 70,
    "skill_name" : "��������"
]),
([      "action" : "$NͻȻ���ǰ�ұۺ󣬳�ʮ���μ�����ǰ��Ȼ���ұ���Ȼ������»�
������ȭ����б���������ͻ�$n�����ǣ�",
    "force" : 550,
    "parry" : 40,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "ʮ���¹�"
]),
([      "action" : "$N��Ȼԭ�ص������һת��$n��ǰ��ʧȥ��$N����Ӱ��$n���������
�䣬ȴ��$NͻȻ��������ǰ��Ц�����ػ�ȭֱ��$n��С������",
    "force" : 600,
    "parry" : 90,
    "dodge" : 80,
    "damage_type" : "����",
    "lvl" : 90,
    "skill_name" : "���γ���"
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�����Ҳ���֮��������֡�\n");
    if ((int)me->query_skill("force", 1) < 30)
   return notify_fail("����ڹ��ķ���򲻹����޷������Ҳ���֮����\n");
    if ((int)me->query("max_neili") < 200)
   return notify_fail("�������̫�����޷������Ҳ���֮����\n");
    if((int)me->query_skill("zuoyou-boji",1)<10)
   return notify_fail("���Ҳ���֮���޷�ͨ��(learn)����ý�����\n");
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
    int i, level;
    level = (int)me->query_skill("zuoyou-boji", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 40)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 30)
   return notify_fail("����������������Ҳ���֮����\n");
    if ((int)me->query_skill("zuoyou-boji",1) < 20)
   return notify_fail("����Ŀǰ�Ĺ����в����Լ���ϰ��\n");
    me->receive_damage("qi", 30);
    switch( random(3) ) {
    case 0:
    me->add("combat_exp", -5);
    write( HIR "��ֻ��������һ���ң�ͷһ���Σ���ľ��齵���ˣ�\n" NOR);
    break;
    case 1:
    me->add("potential", random((int)me->query_con() + (int)me->query_skill("zuoyou-boji",1) )/20);
    me->add("combat_exp", random((int)me->query_con() + (int)me->query_skill("zuoyou-boji",1) )/10);
    write(HIG"�㽫���ֺ����ִ�����ȥ����ϰ���Ҳ���֮������������ʵս���飬Ҳ
��������Ǳ�ܻ������ߡ�\n");
    break;
    case 2:
    me->add("potential", -3);
    write( RED "���������δ��Ǳ����ϰ����Ǳ���½��ˣ�\n" NOR );
    break;
}
}
