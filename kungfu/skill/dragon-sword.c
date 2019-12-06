// mingwang-jian.c ����������
// Designed by secret(����)
//
inherit SKILL;
mapping *action = ({
([      "action" : ""+HIG+"$N��̾һ��,���ϵı�����Ũ.һ�С���Ԩ֮����,����$w����һƬ��Ӱ,��$n�������С�"+NOR+" ",
        "skill_name" : HIC "����" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "����",
]),
 ([      "action" : ""+HIG+"$N����ͻȻ����ʮ������,һʽ������������,����$w�ƺ���������бб����$n��$l  "+NOR+" ",
        "skill_name" : HIM "���ֳ���" NOR,
        "force" : 140,
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : ""+HIG+"$N�����������,�㲻մ�ص�ͽȻ�����߳�,��������$n���ҽ���ȥ,���ǡ�����Ϸˮ�� "+NOR+"",
        "skill_name" : HIY "ɽ��" NOR,
        "force" : 180,
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : ""+HIG+"$N��̤�й���$wһ�С��������项Ѹ���ޱȵ�ֱȡ$n������ "+NOR+"",
        "skill_name" : HIG "ǧ��ת" NOR,
        "force" : 220,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : ""+HIG+"$N�Ǻ�һЦ,һ�С��������ա�,��Ӱ��Ȼ��һ��Ϊ��,������������ʵʵ,ֱ��$n��$l"+NOR+"",
        "skill_name" : MAG "��ħ��" NOR,
        "force" : 250,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : ""+HIG+"$N�����ڿն���һ�����ӷ���˫���ս�����������ʹ�����һ�С�����һ����$wЮ���ż���ķ���ֱ��$nͷ���İٻ�Ѩ"+NOR+" ",
        "skill_name" : HIW "����" NOR,
        "force" : 280,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : ""+HIG+"$Nһ�С�������졹,���ΰεض���.���н�������,����$w����һ����������$n����"+NOR+"  ",
        "skill_name" : YEL "��"BLU"��" NOR,
        "force" : 300,
        "lvl" : 48,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 80;  }
//int valid_combine(string combo) { return combo=="xue-dao"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("mingwang-jian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
   if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("���������������̫ǳ��\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("���С���๦���̫ǳ��\n");
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
    mapping a_action;
    level   = (int) me->query_skill("dragon-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-random(level/3);
    a_action["attack"]  = level/3;
    a_action["damage"] = level;
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
        return notify_fail("������������������˲�����������\n");
    me->receive_damage("qi", 25);
    return 1;
}
