// wuchang-zhang.c �޳��ȷ�
inherit SKILL;
mapping *action = ({
([  "action":"$N΢һ����һ�С�"+BLK+"ӹ������"+NOR+"����$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : BLK "ӹ������" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+RED+"����Ƿ�"+NOR+"����������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
    "force" : 110,
    "lvl" : 7,
    "skill_name" : RED "����Ƿ�" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+GRN+"���񲻰�"+NOR+"��������$wƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
    "force" : 120,
    "lvl" : 14,
    "skill_name" : GRN "���񲻰�" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+YEL+"������ɫ"+NOR+"��������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$1",
    "force" : 130,
    "lvl" : 20,
    "skill_name" : YEL "������ɫ" NOR,
    "damage_type":"����"
]),
([  "action":"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ�С�"+CYN+"�ľ�����"+NOR+"���������к��ų���$n",
    "force" : 140,
    "lvl" : 25,
    "skill_name" : CYN "�ľ�����" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIC+"��ʬ����"+NOR+"����ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
    "force" : 150,
    "lvl" : 30,
    "skill_name" : HIC "��ʬ����" NOR,
    "damage_type":"����"
]),
([  "action":"$N�����ɫ��һ�С�"+HIW+"��������"+NOR+"������$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
    "force" : 300,
    "lvl" : 35,
    "skill_name" : HIW "��������" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIY+"��������"+NOR+"�������⽫$wˤ����ϣ���$n������һ�Ź��𣬻���$n��$l",
    "force" : 350,
    "lvl" : 40,
    "skill_name" : HIY "��������" NOR,
    "damage_type":"����"
]),
([  "action":"$N����װ����һ�С�"+HIG+"��;û·"+NOR+"����һ������������$w��������������$n���ɲ�",
    "force" : 400,
    "lvl" : 45,
    "skill_name" : HIG "��;û·" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIB+"����ľ��"+NOR+"�����������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е�����$n��$l",
    "force" : 450,
    "lvl" : 50,
    "skill_name" : HIB "����ľ��" NOR,
    "damage_type":"����"
]),
([  "action":"$N�߾�$w��һ�С�"+BLU+"�˹���;"+NOR+"������������Ȱ�Ʈ������׼$n�������һ�ȴ���",
    "force" : 500,
    "lvl" : 55,
    "skill_name" : BLU "�˹���;" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+MAG+"�������"+NOR+"�������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
    "force" : 550,
    "lvl" : 60,
    "skill_name" : MAG "�������" NOR,
    "damage_type":"����"
]),
});
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("wuchang-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�޳��ȷ���\n");

    return 1;
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
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuchang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������޳��ȷ���\n");
    me->receive_damage("qi", 30);
    return 1;
}

