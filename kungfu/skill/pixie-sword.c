// pixie-sword.c
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([  "name":    "Ⱥа����",
        "action":  "$Nʹһ�С�Ⱥа���ס�������$wȦ��ٿ�ش̳������ǵ�㣬����ֱ��$n��$l��ȥ",
        "dodge":   50,
        "damage":  100,
        "damage_type":  "����"
    ]),
    ([  "name":    "��ظ��Ŀ",
        "action":  "$Nһ�С���ظ��Ŀ����������ת��Χ��$n��Χ���̣������������$n��$l",
        "dodge":   70,
        "damage":  150,
        "damage_type":  "����"
    ]),
    ([  "name":    "��������",
        "action":  "$N�趯$w��һ�С���������Ю�������������$n��$l",
        "dodge":   40,
        "damage":  100,
        "damage_type":  "����"
    ]),
    ([  "name":    "���Ǹ���",
        "action":  "$N����$wһ����Х�����������Ǹ��¡�������˸������������裬�͵���һ��ͦ����ֱ��$n$l",
        "dodge":   30,
        "damage":  100,
        "damage_type":  "����"
    ]),
    ([  "name":    "���ഩ��",
        "action":  "$N����$w���Ⱪ����һ�С����ഩ������$n$l��ȥ",
        "dodge":   60,
        "damage":  100,
        "damage_type":  "����"
    ]),
    ([  "name":    "����Ū��",
        "action":  "$N����$w����һ���⻡��ֱָ$n$l��һ�С�����Ū�ѡ���������������ȥ",
        "dodge":   10,
        "damage":  100,
        "damage_type":  "����"
    ]),
});

int valid_learn(object me)
{
    object ob;

//    if ( (string)me->query("gender")=="Ů��" )
//        return notify_fail("Ů�Ӳ���ѧ��а����.\n");

//   if ( (string)me->query("gender")=="����" )
//        return notify_fail("��������Թ�,��������а����.\n");

    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취����а������\n");
//   if( (string)me->query_skill_mapped("force")!= "nine-moon-force")
//        return notify_fail("������������������Ͼ����ľ���������\n");
    if( !(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
          return notify_fail("���������һ�ѽ�������������\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 5 )
       return notify_fail("�����������������û�а취��ϰ��а������\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("�㰴����ѧ����һ���а������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
    if( (int)me->query_skill("pixie-sword", 1)  % 10 == 0 ) {
        tell_object(me,
           RED "\n��ͻȻ����һ������������ͷ��ֻ������ɱ��....\n\n"NOR);
        me->add("shen", -2000);
    } else
    me->add("shen", -200);
}
/*
string perform_action_file(string action)
{
    return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}
*/

