// shigu-bifa.c
inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nһ�С�ָ�㽭ɽ��������$w������$n������Ѩ!",
        "force" : 120,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "����"
        ]),
        ([      "action":
"$N��������һ�С�������������$w���������£���$n�׺�Ѩ��ȥ!",
               "force" : 170,
                "dodge" : 15,
                "damage" : 60,
                  "lvl" : 9,
                "damage_type":  "����"

        ]),
        ([      "action":
"$N��ǰ����һ�����������ս�⣬����$wʹ������ƿէ�ơ�������$n�ĵز�Ѩ!",
                 "force" : 190,
                 "dodge" : 10,
                "damage" : 70,
                   "lvl" : 19,
            "damage_type" : "����"

        ]),
        ([      "action":
"$N���е�$w������ҵ�һ�Σ�ʹ��������ͻ�������ź����������$n������Ѩ!",
               "force" : 240,
               "dodge" : 10,
              "damage" : 80,
                 "lvl" : 29,
                 "damage_type":  "����"

        ]),
        ([      "action":
"$N����Ծ��һʽ����ҫ�����������������Ӱ��$w��$n�����ȥ",
                "force" : 280,
                "dodge" : 5,
               "damage" : 90,
                  "lvl" : 39,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�����̨�۾�����һ�ʿ���һ�ʵع���$n",
        "force" : 300,
        "dodge" : 5,
        "damage" : 100,
        "lvl" : 59,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�ң�����项ͦ���й�ֱ�����ʼ��������;��Ȼת�����ϱ���޷�",
        "force" : 330,
        "dodge" : -5,
        "damage" : 120,
        "lvl" : 79,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����б��һ�ʣ�һ�С�������ɷ������ź����ʷ磬��$n��Χ����",
        "force" : 330,
        "dodge" : -5,
        "damage" : 150,
        "lvl" : 99,
                "damage_type":  "����"
        ]),
 });
int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������������û�а취��������ǹ��\n");
        if( (string)me->query_skill_mapped("force")!= "wuzheng-xinfa")
                return notify_fail("ʯ�Ĵ�Ѩ�ʷ�����������ķ���\n");
        if( (int)me->query_skill("wuzheng-xinfa",1) < 20 )
                return notify_fail("��������ķ���򲻹���������ѧϰʯ�Ĵ�Ѩ�ʷ�!\n");
         return 1;
}
mapping query_action(object me, object weapon)
{
       int i, level;
       level   = (int) me->query_skill("shigu-bifa",1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{       object ob;
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "bi" )
                return notify_fail("���������һ���йٱʲ���ѧϰʯ�Ĵ�Ѩ�ʷ���\n");
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 3 )
                return notify_fail("�����������������û�а취��ϰʯ�Ĵ�Ѩ�ʷ���\n");
        me->receive_damage("qi", 20);
        me->add("neili", -10);
        write("�㰴����ѧ����һ��ʯ�Ĵ�Ѩ�ʷ���\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__ "shigu-bifa/" + action;
}

