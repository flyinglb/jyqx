// killsword.c ɱ�ֽ�
// by unix 1998.12
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"
$Nǿѹס����������ԩ�꣬һ����ɱ���ὣ��������$n���ڽ�Ļ֮�У�$N���ͽ���\n"NOR+
HIW"һ���׹�һ����ʧ��$N���е�$w"NOR+HIW"�Ѷ���$n��������Ѩ��\n"NOR,
        "force" : 320,
        "dodge" : 0,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action" : HIB"
$N�ƽ�ŭ��$n��ͻȻ��������ǽ�֮�У�����$w"NOR+HIB"�ڿ�����ͻ�ҹ�\n"NOR+
HIB"�����һ������������������һ��ɱ�֣���ʱ��$næ�ڱ�����\n"NOR,
        "force" : 340,
            "dodge" : 10,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "��Ӱ����",
        "damage_type":  "����"
]),
([      "action" : HIB"
$N���Դݶ���ħ���������ڽ��ϵ�����ԩ�꣬�ݳ����⣬��ʱ����ɱ������ħ��\n"NOR+
RED"Ѫʳ$n��$n��ħ���������߻���ǣ�����������Ѫֱ����\n"NOR,
        "force" : 360,
           "dodge" : 5,
        "damage" : 40,
        "lvl" : 18,
        "skill_name" : "ʳѪħ��",
        "damage_type":  "����"
]),
([      "action" : HIB"
$N��̾���ˣ���֪�м��������Ӳ�֪�й��ˣ���ʱ$N���е�$w"NOR+HIB"��������...\n"
NOR+HIC"����Ȫ��й���󽭶�ȥ�����಻������$n�������̲�ֹ��\n"NOR,
        "force" : 380,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 27,
        "skill_name" : "�󽭶�ȥ",
        "damage_type":  "����"
]),
([      "action" : HIW"
$N��Ŀ�������죬���һ�������е�$w"NOR+HIW"�������й���������� $N������\n"NOR+
HIB"ɱ�ֽ�֮�����ʯ���Ы���������ʱ��$n����������\n"NOR,
        "force" : 420,
        "dodge" : 15,
        "damage": 55,
        "lvl" : 36,
                "skill_name" : "��ʯ�л�",
        "lvl" : 44,
        "damage_type": "����",
]),
([      "action" : HIB"
$NͻȻ������ʦ��������ɱ�ֽ���֮����ʽ������л�������$w"NOR+HIB"�����ֱй\n"
NOR+HIC"$N�ƽ�����$n��������·�������$w"NOR+HIC"������������ֱ��$n\n"NOR,
        "force" : 480,
        "dodge" : 5,
        "damage" : 55,
        "lvl" : 52,
        "skill_name" : "����л�",
        "damage_type":  "����"
]),
([      "action" : HIC"
$NͻȻ������ʦ��������ɱ�ֽ���֮�ڶ�ʽ���������⡹��$N˫�ֺϽ����������ȥ\n"
NOR+HIC"$nһ�󾪶ֻ����ǰ�׹�������������Ȼ��Ŀ������\n"NOR,
        "force" : 500,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action" : HIC"
$NͻȻ������ʦ��������ɱ�ֽ���֮��һʽ��������˪��������$w"NOR+HIC"��ʱ����\n"
NOR+HIC"����̹Ǻ�������$n��˫�ֶ�ס��$N��������ֱ��$nԴѨ��\n"NOR,
        "force" : 580,
        "dodge" : 10,
        "damage": 70,
        "lvl" : 70,
        "skill_name" : "������˪",
        "damage_type":  "����"
]),
([      "action" : HIB"
$N�������������᲻�����ˣ�Թ���˲����� $NԹ���ߴ�����$w"NOR+HIB"������Ѫ\n"NOR+
RED"��ʱ$N����ħ�Դ󷢣��������֣��������ߣ� $N�Ѱ��ղ�ס���е�$w"NOR+YEL"����
\n"NOR+HIW"     ��˫��ʮ���ɫ�����ն��\n"NOR,
        "force" : 580,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "��ʷ����",
        "damage_type":  "����"
]),
([      "action" : HIW"
$N�����ݽ�����߽��������ˡ�ɱ�ֽ����ľ�ѧ�����ΰ�Ѩ���಻����\n"NOR+
YEL"$N�ٸ���������󽭱��ڣ������޾������Ű׻ܷ�������$N���һ����\n"NOR+
HIY"    �����������������\n"NOR,

        "force" : 580,
        "dodge" : 15,
        "damage": 100,
        "lvl" : 90,
        "set_name" : "���ΰ�Ѩ",
        "damage_type":  "����"
]),
([      "action" : HIB"
$N��Ŀ��Դ�������ϵ�ɱ�����ڽ��ˣ�Ŀ�����ߣ����潣����������ɱ���ݽ�����\n"NOR+
HIC"ɱ��Ƭ�ط�ɰ���������죬����Ψ���᲻�����Ƴ�����˭���뽣���磡\n"NOR,
        "force" : 680,
        "dodge" : 15,
        "damage": 220,
        "lvl" : 114,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
me=this_player();
if(me->query_skill("force")<30)
return notify_fail("��Ļ����ڹ���Ϊ����ѧɱ�ֽ���\n");
if(me->query_skill("sword")<30)
return notify_fail("��Ļ�����������ѧɱ�ֽ���\n");
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
        int i, level;
        level = (int) me->query_skill("killsword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/50)];
}

int practice_skill(object me)
{
        object weapon;


        if(this_player()->query_skill("shenghuo-gong")<30)
        return notify_fail("�㻹Ҫ��ʥ������������ǿ��\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
        return notify_fail("�������������ɱ�ֽ���\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"killsword/" + action;
}

