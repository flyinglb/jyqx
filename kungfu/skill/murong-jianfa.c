// murong-jiafa Ľ�ݽ���

inherit SKILL;

mapping *action = ({
([      "action" : "$N������ָ��һʽ��ϴ����������˫�ź�������������ֱ��$n�Ȳ�",
        "force" : 100,
        "dodge" : 20,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰ�����������ʵ������ʹһʽ�����������ֱ��$n������",
        "force" : 100,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������������ⶶ����佣�����ֱ����$n���������Ҷ�",
        "force" : 140,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N�����ڣ�����ָ��$n��������һ�С�����Ī��������������ǧ��һ�㣬��ɨ$n��$l",
        "force" : 200,
        "dodge" : 10,
        "damage" : 100,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ�С��ﻢ���¡��������й���ƽ��$n��$l",
        "force" : 260,
        "dodge" : 5,
        "damage" : 120,
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ�����ὣб����һ�С���ש���񡹣��������$n��$l",
        "force" : 300,
        "dodge" : -5,
        "damage" : 140,
        "lvl" : 100,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("murong-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 20)
                return notify_fail("�������������Ľ�ݽ�����\n");
		if ((int)me->query("neili") < 20)
                return notify_fail("�������������Ľ�ݽ�����\n");
        me->receive_damage("jing", 20);
		me->add("neili",-15);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");

   if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
      && me->query_skill_prepared("finger") == "canhe-zhi"
      && me->query_skill_mapped("finger") == "canhe-zhi"
      && objectp(weapon)) {
        me->set_temp("lianhuan_hit", 1);
        weapon->unequip();
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
        weapon->wield();
        me->add("neili", -30);
        me->delete_temp("lianhuan_hit");
        me->add_temp("lianhuan", -1);
        }
}

