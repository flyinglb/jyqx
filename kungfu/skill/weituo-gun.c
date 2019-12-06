// weituo-gun.c -Τ�ӹ�
inherit SKILL;
mapping *action = ({
([  "action":"$Nһ�С�"+YEL+"��ʯ����"+NOR+"��������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ",
    "force" : 160,
    "lvl" : 0,
    "skill_name" : YEL "��ʯ����" NOR,
    "damage_type":"����"
]),
([  "action":"$N��$wƽ���ؿڣ�һš��һ�С�"+WHT+"����ͣ��"+NOR+"����$w�͵�����$n�ľ���",
    "force" : 180,
    "lvl" : 8,
    "skill_name" : WHT "����ͣ��" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIM+"ƽ������"+NOR+"����ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ����ȥ",
    "force" : 210,
    "lvl" : 16,
    "skill_name" : HIM "ƽ������" NOR,
    "damage_type":"����"
]),
([  "action":"$N����һ��������һ�С�"+HIM+"��������"+NOR+"����$wЮ��������Ѹ��ɨ��$n������",
    "force" : 250,
    "lvl" : 25,
    "skill_name" : HIM "��������" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+HIW+"���Ǹ���"+NOR+"���������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
    "force" : 300,
    "lvl" : 35,
    "skill_name" : HIW "���Ǹ���" NOR,
    "damage_type":"����"
]),
([  "action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С�"+RED+"��ϼ��"+HIW+"��"+NOR+"����һ����Բ�����л�����ײ��$n���ؿ�",
    "force" : 350,
    "lvl" : 44,
    "skill_name" : RED "��ϼ����" NOR,
    "damage_type":"����"
]),
([  "action":"$Nһ�С�"+MAG+"Ͷ�޶���"+NOR+"����$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����",
    "force" : 410,
    "lvl" : 52,
    "skill_name" : MAG "Ͷ�޶���" NOR,
    "damage_type":"����"
]),
([  "action":"$NǱ��������һ�С�"+HIC+"�����麣"+NOR+"����$w��ʱ�������ɣ�������ֱ��$n���ؿ�",
    "force" : 470,
    "lvl" : 60,
    "skill_name" : HIC "�����麣" NOR,
    "damage_type":"����"
]),
});
int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("club", 1) <=me->query_skill("weituo-gun", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧΤ�ӹ���\n");
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
        level   = (int) me->query_skill("weituo-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�������������Τ�ӹ���\n");
    me->receive_damage("qi", 25);
    return 1;
}
