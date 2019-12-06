// chousui-duzhang.c  ������, based on xianglong-zhang.c
// modified by Venus Oct.1997
// by yucao

inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
    "dodge": 30,
    "force": 160,
//      "poison": 80,
    "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
    "dodge": 10,
    "force": 160,
//      "poison": 60,
    "damage_type": "����"
]),
([      "action": "$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
    "dodge": -20,
    "force": 150,
//      "poison": 100,
    "damage_type": "����"
]),
([      "action": "$N˫��Ю��һ���ȳ�֮������$n��$l",
    "dodge": 10,
    "force": 160,
//      "poison": 80
    "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry"; }   

int valid_combine(string combo) { return combo=="sanyin-wugongzhao"; }

mapping query_action(object me)
{
    if (random(me->query_skill("unarmed",1)) > 60 &&
        me->query_skill("force",1) > 50 &&
        me->query("neili") > 100 ) {
             me->add("neili", -100);
             return ([
                  "action": "$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n",
                  "force": 300,
                  "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("huagong-dafa", 1) < 10)
       return notify_fail("��Ļ����󷨻�򲻹����޷��������ơ�\n");
    if ((int)me->query("max_neili") < 60)
       return notify_fail("�������̫�����޷��������ơ�");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 8)
        return notify_fail("������������������ơ�\n");
    if (me->query_skill("chousui-zhang", 1) < 50)
        me->receive_damage("qi", 20);
    else
        me->receive_damage("qi", 30);
         me->add("neili", -5);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
   //if( random(me->query_skill("huagong-dafa",1)) > (damage_bonus + foo)/3 )
    if( random(me->query_skill("huagong-dafa",1)) > 5) {
   //victim->receive_wound("qi", (damage_bonus + foo));
   victim->apply_condition("xx_poison", random(2) + 1 +
      victim->query_condition("xx_poison"));
    }
}
string perform_action_file(string action)
{
    return __DIR__"chousui-zhang/" + action;
}
