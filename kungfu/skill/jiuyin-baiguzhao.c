//jiuyin-baiguzhao.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action" : "$N��צ��Σ���צ������һ�С�"+HIW+"�������"+NOR+"��ֱ����$n��$l",
    "force" : 320,
    "lvl"   : 0,
    "skill_name" : "�������" ,
    "damage_type" : "ץ��"
]),
([  "action" : "$N˫��������צ��צצ����$n����"+HIW+"��������"+NOR+"������$n��$lץ��",
    "force" : 380,
    "lvl"   : 20,
    "skill_name" : HIW "��������" NOR ,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��ʹ����"+HIW+"���޵���"+NOR+"����$n��$l����ȫ������צӰ��",
    "force" : 440,
    "lvl"   : 40,
    "skill_name" : HIW "���޵���" NOR ,
    "damage_type" : "ץ��"
]),
([  "action" : "$Nʹһ�С�"+HIW+"������"+NOR+"����˫צ�ó�����צӰץ��$nȫ��",
    "force" : 520,
    "lvl"   : 60,
    "skill_name" : HIW "������" NOR ,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����������һ�С�"+RED+"Ψ�Ҷ���"+NOR+"��˫צ������$n�������",
    "force" : 620,
    "lvl"   : 100,
    "skill_name" : RED "Ψ�Ҷ���" NOR ,
    "damage_type" : "ץ��"
]),
});
  int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������׹�צ������֡�\n");
    if ((int)me->query("max_neili") < 200)
            return notify_fail("�������̫�����޷��������׹�צ��\n");
      if (me->query_skill("claw", 1) <=me->query_skill("jiuyin-baiguzhao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i-1]["lvl"])
            return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    int i, level;
    mapping a_action;
    level   = (int) me->query_skill("jiuyin-baiguzhao",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
      a_action["dodge"]  = level;
    a_action["attack"]  = level;
    a_action["damage"] = level*2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������׹�צ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("������������������׹�צ��\n");
    me->receive_damage("qi", 30);
        me->add("neili", -20);
    return 1;
}
void skill_improved(object me)
{
    tell_object(me, HIR "���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�\n" NOR );
    me->add("shen", -me->query_skill("jiuyin-baiguzhao",1)*6);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_str()*2) > victim->query_str() ) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2,me );
        return HIR "��������������һ�����죬�����ǹ����������\n" NOR;
    }
}
