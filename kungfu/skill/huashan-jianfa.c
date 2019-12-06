// huashan-jianfa.c ��ɽ����
inherit SKILL;
#include <combat.h>

mapping *action = ({
([  "action" : "$Nһ�С�"+YEL+"���Ƴ��"+NOR+"��������$w����$n��$l",
    "damage" : 20,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����"+RED+"�з�����"+NOR+"����$w��˸����������$n��$l",
    "damage" : 25,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+MAG+"������"+NOR+"����$w���϶��»���һ���󻡣���$n������ȥ",
    "damage" : 30,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ����һ��������$wʹ����"+BLU+"�׺����"+NOR+"��ֱ��$n��$l",
    "damage" : 35,
    "damage_type" : "����"
]),
([      "action" : "$N���е�$wһ�Σ�ʹ����"+HIM+"����ӭ��"+NOR+"��ֱ��$n��$l",
        "damage" : 50,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 20)
        return notify_fail("��Ļ�ɽ�ڹ����̫ǳ��\n");
    if (me->query_skill("sword", 1) <=me->query_skill("huashan-jianfa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    a_action = action[random(sizeof(action))];
    a_action["dodge"]=me->query_skill("sword")/2;
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
        return notify_fail("���������������ɽ������\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huashan-jianfa/" + action;
}

void do_interlink(object me, object victim)
{
    int skill1,skill2,j;
    string second_skill;
    if (me->query_temp("secondary_weapon")) return;
    second_skill = me->query_skill_mapped("unarmed");
    if (!second_skill || second_skill!="huashan-zhangfa" )   return;
    skill1=me->query_skill("huashan-jianfa", 1);
    skill2=me->query_skill("huashan-zhangfa", 1);
    if (random(skill1)>100 && random(skill2)>100){
    message_vision(HIY "\n$Nʹ����ɽ�ɾ�����������������������Ȼ�ӿ죡\n\n" NOR,me);
    for (j=0;j<5;j++)
       if ((me->is_fighting(victim) || victim->is_fighting(me)) && victim->query("qi")>0 ){
         if (environment(me) == environment(victim)){
              if (j%2==0)
                    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              else{
                    me->set_temp("secondly_weapon",1);
                    COMBAT_D->do_attack(me, victim, 0, TYPE_QUICK);
                    me->delete_temp("secondly_weapon");
              }
         }
       }else break;
    }
}

