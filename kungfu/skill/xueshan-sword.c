// xueshan-sword ѩɽ����
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$N����$w���ͣ�һ��"+(order[random(13)])+"�������ơ�"NOR"��ǰ�̳�,����$n��$l",
        "force" : 50,
        "dodge" : -10, 
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N������ǰ���������������һʽ"+(order[random(13)])+"����ѩ�ŵ㡹"NOR"��$n���Ƶ��ۻ����ң���æ����֮�ʣ�\nͻȻ��$l��һ������",
        "force" : 50,
        "dodge" : -10,
        "damage": 220,
        "lvl" : 7,
        "skill_name" : "��ѩ�ŵ�",
        "damage_type":  "����"

]),
([      "action":"$N����ٿ�ط��ϣ�б��$n��$l������ѩɽ�ɽ����е�"+(order[random(13)])+"����֦��б��"NOR"",
        "force" : 70,
        "dodge" : -7,
        "damage": 250,
        "lvl" : 14,
        "skill_name" : "��֦��б",
        "damage_type":  "����"

]),
([      "action":"$N����һ��������$n�����мܣ�$N���ٺ���������������ʱ���У���ת���棬\nб���к�����ѩɽ�ɽ����е�"+(order[random(13)])+"��ѩ���צ��"NOR"",
        "force" : 80,
        "dodge" : -5,
        "damage": 300,
        "lvl" : 21,
        "skill_name" : "ѩ���צ",
        "damage_type":  "����"

]),
([      "action":"$N����$wһ��"+(order[random(13)])+"��������Ӱ��"NOR"����������Ӱ�������������ޣ�б��������$n���Եֵ�����һ������$l",
        "force" : 100,
        "dodge" : -5, 
        "parry" : 10,
        "damage": 320,
        "lvl" : 28,
        "skill_name" : "������Ӱ",
        "damage_type":  "����"

]),


([      "action":"$N����$w�������Ȧ�ӣ�һ��"+(order[random(13)])+"��˷�����"NOR"�������â����Х����$n���ζ�ȥ",
        "force" : 100,
        "dodge" : -5, 
        "parry" : 10,
        "damage": 350,
        "lvl" : 35,
        "skill_name" : "˷�����",
        "damage_type":  "����"

]),
([      "action":"$Nһʽ"+(order[random(13)])+"������������"NOR"������$w���Ƴ��Ͳ�����ȴ����ʵ�죬��$n�Ѷ���ʵ���޿ɶ��",
        "force" : 110,
        "dodge" : -5,
        "parry" : 10, 
        "damage": 380,
        "lvl" : 42,
        "skill_name" : "��������",
        "damage_type":  "����"

]),

([      "action":"$N��Ȼ�ս��ػ���һʽ"+(order[random(13)])+"����ɳ��ʯ��"NOR"���͵ؼ��������Ҷ��ʯ�Ĵ����Ю�ޱ����ƣ���$n$l��ȥ",
        "force" : 120,
        "dodge" : -5,
        "parry" : 10, 
        "damage": 400,
        "lvl" : 49,
        "skill_name" : "��ɳ��ʯ",
        "damage_type":  "����"

]),
([      "action":"$N�ٽ�����Ծ����һʽ"+(order[random(13)])+"������Խ�롹"NOR"��$w�ó������â���ڽ����м�ȡ$n��$l",
        "force" : 150,
        "dodge" : 0,
        "damage": 420,
        "lvl" : 56,
        "skill_name" : "����Խ��",
       "damage_type":  "����"

]),


([      "action":"$N���ֽ��ս�ָ���ҽ�Ĭ�˱�ѩ�ķ���������������͸����һʽ"+(order[random(13)])+"������˫÷��"NOR"��\n��ָ�������Ҽй���ֱ��$n$l",
        "force" : 180,
        "dodge" : 0,
        "damage": 450,
        "lvl" : 63,
        "skill_name" : "����˫÷",
       "damage_type":  "����"

]),
([      "action":"$Nһʽ"+(order[random(13)])+"������Ǽ�ѡ�"NOR"��$w����һ�����»��Σ�����������⣬����$n��$l",
        "force" : 200,
        "dodge" : 5,
        "damage": 480,
        "lvl" : 70,
        "skill_name" : "����Ǽ��",
        "damage_type":  "����"

]), 
([      "action":"$Nһ��"+(order[random(13)])+"����ɫ�ƻ衹"NOR"��ʹ���������ޣ��������ʣ�$wбб������ֱȡ$n$l",
        "force" : 220,
        "dodge" : 5,
        "parry" : 10,
        "damage": 500,
        "lvl" : 77,
        "skill_name" : "��ɫ�ƻ�",
        "damage_type":  "����"

]), 
([      "action":"$N����$w������һ��"+(order[random(13)])+"��÷ѩ������"NOR"��������ʵ��ʵ�����飬���⽣�����ã�\n������ѩ�㣬�����˸�֦������˷�����$n���˹���",
        "force" : 250,
        "dodge" : 5,
        "damage": 520,
        "lvl" : 84,
        "skill_name" : "÷ѩ����",
        "damage_type":  "����"

]), 

([      "action":"$N����$w˦����һ��"+(order[random(13)])+"���׷ɾ��졹"NOR"���ڿ����������ģ����������$n�̳��ž�\n��ʮһ����Ȼ��ɻ�$N����",
        "force" : 300,
        "dodge" : 5,
        "damage": 550,
        "lvl" : 91,
        "skill_name" : "�׷ɾ���",
        "damage_type":  "����"

]), 
([      "action":"$N��Хһ�������ӿ죬һ��"+(order[random(13)])+"����Ӱ���㡹"NOR"��$w��÷������ݳ���$n�����ɼ䣬\n����ͻȻ��������,����������$n���ֶ�ȥ",
        "force" : 350,
        "dodge" : 5,
        "damage": 600,
        "lvl" : 100,
        "skill_name" : "��Ӱ����",
        "damage_type":  "����"

]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취��ѩɽ������\n");
   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("ѩɽ����������ϱ�ѩ�ķ���������\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�������������\n");

    return 1;
}

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

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
        level   = (int) me->query_skill("xueshan-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 20
        ||      (int)me->query("neili") < 10 )
                return notify_fail("�����������������û�а취��ϰѩɽ������\n");
        me->receive_damage("qi", 15);
        me->add("neili", -5);
        write("�㰴����ѧ����һ��ѩɽ������\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xueshan-sword/" + action;
}

