//
// riyue-lun.c �����ַ�
//
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹһ�С�"+GRN+"������"+NOR+"�����������е�$w��$n��$l��ȥ  ",
        "skill_name" : GRN "������" NOR,
        "force" : 120,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�"+YEL+"��ɽ����"+NOR+"����˫��һ�����趯����$w��$n��$l��ɨ  ",
        "skill_name" : YEL "��ɽ����" NOR,
        "force" : 160,
        "lvl" : 22,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�"+MAG+"��΢��"+NOR+"�����͵�һ��������$w���¶�������$n��$l  ",
        "skill_name" : MAG "��΢��" NOR,
        "force" : 200,
        "lvl" : 45,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�"+BLK+"������"+NOR+"�����������֮��$wɨ��$n��$l  ",
        "skill_name" : BLK "������" NOR,
        "force" : 240,
        "lvl" : 68,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�"+HIM+"Բ����"+NOR+"����$w������֮����ֱ��$n��$l  ",
        "skill_name" : HIM "Բ����" NOR,
        "force" : 290,
        "lvl" : 92,
        "damage_type" : "����",
]),
([      "action" : "$NԾ���գ�ʹһ�С�"+HIC+"���ػ���"+NOR+"�����߾�$w����$n��$l  ",
        "skill_name" : "���ػ���",
        "force" : 320,
        "lvl" : 114,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�"+HIW+"׽����"+NOR+"����б������$w����$n��$l  ",
        "skill_name" : HIW "׽����" NOR,
        "force" : 360,
        "lvl" : 136,
        "damage_type" : "����",
]),
([      "action" : "$N��һ��������ʹ����"+RED+"�Լ���"+NOR+"����$wɨ��$n��ͷ��  ",
        "skill_name" : RED "�Լ���" NOR,
        "force" : 400,
        "lvl" : 160,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }
int practice_level(){   return 160;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("longxiang", 1) < 100)
        return notify_fail("���������������̫ǳ��\n");
    if (me->query_skill("hammer", 1) <=me->query_skill("riyue-lun", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("riyue-lun",1);
    if (level>100 && me->query("neili")>50){
       me->add_temp("riyue_no", 1);
       if (me->query_temp("riyue_no")>20){
            me->set_temp("riyue_no", 0);
            message_vision( BOLD"\n$N��������˿�������Ȼ���е����ˣ�\n"NOR, me);
            me->set_temp("str",0);
       }else if( (int)me->query_temp("riyue_no") % 2 ){
            message_vision( HIY"\n$N������һ����������"+me->query_temp("weapon")->name()+HIY+"������������\n"NOR, me);
            me->add_temp("str",level/10);
            me->add("neili",-50);
       }
    }
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "hammer")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "hammer")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�����������,�����������ַ���\n");
    me->receive_damage("qi", 40);
    return 1;
}
