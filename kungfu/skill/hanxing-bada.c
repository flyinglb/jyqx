//hanxing-bada.c ���ǰ˴�
inherit SKILL;

mapping *action = ({
        ([      "action":"$Nʹһ�С�����է�֡�������$w����$n��$l",
                "force": 120,
                "dodge": -20,
                "damage":90,
                "lvl" : 0,
                "skill_name" : "����է��",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$Nʹ�����������ա���˫���³�$w�������Ϸɳ�ֱϮ$n��$l",
                "force": 125,
                "dodge":  -20,
                "damage": 50,
                "lvl" : 10,
                "skill_name": "��������",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$Nһ�С�ĺ��������������һ�ӣ�����$w��Ҹ�¼���$n��$l",
                "force":135,
                "dodge": -30,
                "damage":40,
                "lvl" : 20,
                "skill_name": "ĺ������",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N����$wһʽ�������ѿա���$w����һ���׹�ֱ��$n��$l",
                "force":140,
                "dodge": -40,
                "damage":60,
                "lvl" : 30,
                "skill_name": "�����ѿ�",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N����һԾ������$wһ�С������뺣������$n��$l",
                "force":150,
                "dodge": -40,
                "damage": 70,
                "lvl" : 40,
                "skill_name":"�����뺣",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N�ֿ�$w,ƾ��һָ��һ�С���ɽҹ�꡹����$n��$l",
                "force":160,
                "dodge": 20,
                "damage":50,
                "lvl" : 50,
                "skill_name": "��ɽҹ��",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N����һ�Σ�ʹһ�С����Ǻ�ա�$w���ֶ�����Ϯ��$n��$l",
                "force":220,
                "dodge": -20,
                "damage":60,
                "lvl" : 60,
                "skill_name": "���Ǻ��",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N����һת����$wʹһ�С��������ա�����һ���⻡Ϯ��$n��$l",
                "force":270,
                "dodge": -30,
                "damage":60,
                "lvl" : 100,
                "skill_name": "��������",
                "damage_type":  "����",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������������û�а취�����ǰ˴�\n");
       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ����֮��Ķ���������������\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry";
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
        level = (int) me->query_skill("hanxing-bada",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 ||(int)me->query("neili") < 3 )
                return notify_fail("�����������������û�а취��ϰ���ǰ˴�\n")
;
        me->receive_damage("qi", 30);
        me->add("neili", -3);
        write("�㰴����ѧ����һ�麮�ǰ˴�\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hanxing-bada/" + action;
}

