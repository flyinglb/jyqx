inherit SKILL;
mapping *action = ({
    ([  "action":       "$Nʹһ�С�"+HIY+"������"+CYN+"ͼһ��"+NOR+"��������$w��$n��$l��ն�ߵ���",
        "damage":       200,
        "dodge":        200,
        "damage_type":  "����"
    ]),
    ([  "action":       "$N������ת��$w����һ�С�"+YEL+"�´�"+RED+"�����ղ���"+NOR+"�����¶�������$n��$l",
        "damage":       400,
        "damage_type":  "����"
    ]),
    ([  "action":       "$N����һת��һ�С�"+WHT+"Ϊ����������"+NOR+"��$w���ⲻ����ն��$n��$l",
        "damage":       200,
        "damage_type":  "����"
    ]),
    ([  "action":       "$N�趯$w��һ�С�"+HIW+"����Σ¥��ϸϸ"+NOR+"��Ѹ�����׵�����$n��$l",
        "damage":       200,
		"damage_type":  "����"
    ]),
    ([  "action":       "$N����$wһ�Σ�һ�С�"+HIB+"����˭��ƾ����"+NOR+"����$n��$lбб����һ��",
        "damage":       400,
        "damage_type":  "����"
    ]),
    ([  "action":       "$N�ᵶ���磬�������һ�С�"+HIG+"��ɫ�̹������"+NOR+"��ֱ��$n$l",
        "damage":       400,
        "damage_type":  "����"
    ]),
    ([  "action":       "$N���һ����ʹ���ɷ���������һ�С�"+BLU+"���ɷ"+NOR+"��$w����һ��ʺ�ն��$n��$l",
        "damage":       300,
        "damage_type":  "����"
    ]),
});
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("blade", 1) <=me->query_skill("tiangang-blade", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
int valid_enable(string usage)
{
    return (usage=="blade") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    object weapon;
    if( !objectp(weapon = me->query_temp("weapon"))
    ||  (string)weapon->query("skill_type") != "blade" )
        return notify_fail("���������һ�ѵ���������������\n");
    if( (int)me->query("qi") < 40 )
        return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
    me->receive_damage("qi", 40);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_str()*2) > victim->query_str() ) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
        return HIR "��ֻ�������󵶷磬�����������������һ���Һ�!�\n" NOR;
    }
}

