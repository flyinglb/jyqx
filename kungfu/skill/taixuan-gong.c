// taixuan-gong.c ���͵�̫����
// Jay 4/5/96
// modified by wind
inherit FORCE;

string *dodge_msg = ({
    "$n�����ĳ������絽������$N��һ�ߡ�\n",
    "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
    "$n������ţ���Ծ��������������ʮ�����⡣\n",
    "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

mapping *action = ({
([  "action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
    "force" : 200,
    "dodge" : 20,
    "damage": 240,
    "damage_type":  "����"
]),
([  "action":"$N�����������$n�۰���Ѹ���ޱȵ�һ����$nһ�ӵ��˳�ȥ",    
    "force" : 220,
    "dodge" : 20,
    "damage": 250,
    "damage_type":  "����"
]),
([  "action":"$N���һ�����ſ�һ��������$n������ȥ",
    "force" : 400,
    "dodge" : 30,
    "damage": 250,
    "damage_type":  "����"
]),
([  "action":"$N�����ϣ�˫���͵�����$n",
    "force" : 225,
    "dodge" : 30,
    "damage": 270,
    "damage_type":  "����"
]),
([  "action":"$N����΢�࣬ͻȻ����һ�ţ�����$n����·���ŵ���;���͵�һ̧������$n����",
    "force" : 230,
    "dodge" : 40,
    "damage": 300,
    "damage_type":  "����"
]),
([  "action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
    "force" : 230,
    "dodge" : 40,
    "damage": 300,
    "damage_type":  "����"
]),

});

int valid_enable(string usage)
{
    return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("taixuan-gong",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
       return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    if (random(this_player()->query("kar")) > 25)
        return 1;
    return notify_fail("�����ʯ��ڤ˼������һ�ᣬ����Ŀ�����һ�㲻����\n");
}

string exert_function_file(string func)
{
    return __DIR__"taixuan-gong-e/" + func;
}

string perform_action_file(string action)
{
    return __DIR__"taixuan-gong-p/" + action;
}
