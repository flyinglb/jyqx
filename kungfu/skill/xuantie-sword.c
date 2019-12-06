inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nʹ��һ�С��������ա������е�$w����һ��Բ������$n��$l����",
                "dodge":                30,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���������ĳ�һ�ƣ������е�$wʹ��һ�С��һ����ơ���ն��$n��$l",
                "dodge":                10,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�ˮ�����ɡ�������������ˮ������$w���������ն��$n��$l",
                "dodge":                50,
                "damage":               10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һʽ�ġ������ķ�����׼$n��$l�̳�һ��",
                "dodge":                20,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$w���μ������У�һ�С�����������$n��ȥ",
                "dodge":                60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫���ս���ʹ��һ�С���Ŀ�ѻԡ�����$n��$l",
                "dodge":                100,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���н�����һ�Σ�$w��Ϊһ����⣬ʹ����������ġ�����$n��$l",
                "dodge":                100,
                "damage":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "��Ĺ��"|| myfam["master_id"] != "yang guo")
                return notify_fail("��������ֻ�������ѧϰ��\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취������������\n");
        if( (int)me->query_skill("yunv-xinfa",1)<100)
                return notify_fail("�����Ů�ķ��ȼ�������\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if ((int)me->query_skill("xuantie-sword",1) > 90)
                return notify_fail("�������������Ժ��Ҫ�����Լ����ˡ�\n");

        return 1;
}

int valid_enable(string usage)       
{
	return (usage=="sword") || (usage=="parry") ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( !environment(me)->query("valid_xuantie-sword") )
                return notify_fail("��������û��ѧϰ����������\n");

        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 5 )
                return  notify_fail("�����������������û�а취��ϰ����������\n");
        if(me->query_skill("xuantie-sword",1)>80)
                return notify_fail("������ֻ��ͨ������ʽ���������������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}


string *parry_msg = ({
        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С��������ġ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-sword/" + action;
}


