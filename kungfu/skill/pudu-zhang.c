// pudu-zhang.c �ն��ȷ�
inherit SKILL;
mapping *action = ({
([  "action":"$Nʹһ�С�"+YEL+"��ţת��"+NOR+"��������$w���¶��ϣ������ޱȵ���$n��С����ȥ��",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "��ţת��" NOR,
    "damage_type":"����"
]),
([  "action":"$N�첽�����һ�С�"+RED+"Ұ��׷��"+NOR+"��������ƽ��$w�����������ȶˣ�����$n���ؿڡ�",
    "force" : 200,
    "lvl" : 12,
    "skill_name" : RED "Ұ��׷��" NOR,
    "damage_type":"����"
]),
([  "action":"$N�߾�$w��һ�С�"+BLK+"�ͻ�����"+NOR+"����ȫ��Ծ������$w§ͷ�Ƕ�����$n��ȥ��",
    "force" : 230,
    "lvl" : 23,
    "skill_name" : BLK "�ͻ�����" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIY+"ʨ��ҡͷ"+NOR+"����˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���һ�����硣",
    "force" : 270,
    "lvl" : 36,
    "skill_name" : HIY "ʨ��ҡͷ" NOR,
    "damage_type":"����"
]),
([  "action":"$N���$w��һ�С�"+WHT+"������β"+NOR+"�����ȶ˻���������ԲȦ�����ͳ��أ���$n�������С�",
    "force" : 320,
    "lvl" : 48,
    "skill_name" : WHT "������β" NOR,
    "damage_type":"����"
]),
([  "action":"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С�"+HIC+"��������"+NOR+"������Ӱ��$n��������",
    "force" : 380,
    "lvl" : 60,
    "skill_name" : HIC "��������" NOR,
    "damage_type":"����"
]),
([  "action":"$N˫�ֺ�ʮ������һ�С�"+GRN+"��ɮ�в�"+NOR+"����$w������ɳ���������$nײȥ��",
    "force" : 450,
    "lvl" : 72,
    "skill_name" : GRN "��ɮ�в�" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+RED+"��"+YEL+"��"+MAG+"��"+BLU+"��"+NOR+"����$w�������������Ծ����ֱ��$n���ؿڴ��롣",
    "force" : 530,
    "lvl" : 80,
    "skill_name" : MAG "�Ⱥ��ն�" NOR,
    "damage_type":"����"
]),
});
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int practice_level(){   return 90;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("pudu-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�ն��ȷ���\n");
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
    level   = (int) me->query_skill("pudu-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level/3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������ն��ȷ���\n");
    me->receive_damage("qi", 30);
    return 1;
}
