// luoying-shenjian.c ��Ӣ��
#include <ansi.h>
inherit SKILL;
mapping *action = ({
    ([  "name":         RED "��Ӣ�ͷ�" NOR,
        "action":       "$Nʹһ�С�"+RED+"��Ӣ�ͷ�"+NOR+"������������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l",
        "force":        100,
    "damage_type":  "����"
    ]),
    ([  "name":         RED "�����һ�" NOR,
        "action":       "$N�趯$w��һʽ��"+MAG+"�����һ�"+NOR+"����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l",
        "force":        140,
        "damage_type":  "����"
    ]),
    ([  "name":         MAG "��������" NOR ,
        "action":       "$N������$nһת������$w����һָ��һʽ��"+MAG+"��������"+NOR+"���ó����콣Ӱ����$n$l�����ӳ�����",
        "force":        180,
        "damage_type":  "����"
    ]),
    ([  "name":         RED "���Ƿɻ�" NOR,
        "action":       "$N����ƮȻ�����ڰ��������һ������Ȼһʽ��"+RED+"���Ƿɻ�"+NOR+"������$w�������޵�������$n��$l",
        "force":        210,
        "damage_type":  "����"
    ]),
    ([  "name":         WHT "������" NOR,
        "action":       "$N�������࣬ͷ�½��ϣ�һ�С�"+BLU+"������"+NOR+"������$w���һ����������$n��$l",
        "force":        240,
    "damage_type":  "����"
    ]),
    ([  "name":         BLK "���컨��" NOR,
        "action":       "$Nһ�����ʹ����"+HIC+"���컨��"+NOR+"��������$w�ó����컨�꣬Ѹ����������$n��$l",
        "force":        280,
    "damage_type":  "����"
    ]),
    ([  "name":         MAG "�仨����" NOR,
        "action":       "$N��̾һ��������$w����һ����һʱ��"+HIY+"�仨����"+NOR+"����$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
        "force":        320,
    "damage_type":  "����"
    ]),
});
int practice_level(){   return 110;  }
int valid_learn(object me)
{
    object ob;
    if( (int)me->query_skill("bibo-shengong",1) < 30)
        return notify_fail("��ı̲��񹦻�򻹲�����\n");
    if( (int)me->query("max_neili") < 100 )
        return notify_fail("���������������������Ӣ�񽣡�\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("���������һ�ѽ�����ѧϰ������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("luoying-shenjian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
    int level=me->query_skill("luoying-shenjian",1);
    mapping a_action = action[random(sizeof(action))];
    a_action["dodge"]=0-level/3;
    a_action["attack"]=level/3;
    a_action["damage"]=level/2;
    return a_action;
}
int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 15 )
        return notify_fail("�����������������û�а취��ϰ��Ӣ�񽣡�\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("���������һ�ѽ�����ϰ��������\n");
    me->receive_damage("qi", 30);
    me->add("force", -10);
    return 1;
}
