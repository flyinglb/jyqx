// xianglong-zhang.c ����ʮ����
#include <combat.h>
inherit SKILL;
mapping *action = ({
([  "action": "$Nʹ����"+HIC+"ͻ������"+NOR+"�������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
    "force": 130,
   "damage_type": "����"
]),
([  "action": "$N����һ�С�"+HIC+"��������"+NOR+"����Ѹ���ޱȵ�����$n��$l",
    "force": 150,
    "damage_type": "����"
]),
([  "action": "$N˫��ʩ��һ�С�"+HIC+"�轥��½"+NOR+"�����������ŷ�������$n��$l",
    "force": 170,
    "damage_type": "����"
]),
([  "action": "$N���λ�����˫��ʹһ�С�"+HIC+"˫��ȡˮ"+NOR+"��һǰһ����$n��$l",
    "force": 190,
    "damage_type": "����"
]),
([  "action": "$NͻȻ���η���˫�ƾӸ�����һ�С�"+HIC+"��������"+NOR+"������$n��$l",
    "force": 210,
    "damage_type": "����"
]),
([  "action": "$N���ƾ۳�ȭ״������һ�С�"+RED+"Ǳ������"+NOR+"����������$n��$l",
    "force": 220,
    "damage_type": "����"
]),
([  "action": "$Nʹ����"+RED+"����ެ"+NOR+"����˫���������ϻ���$n��$l",
    "force": 230,
    "damage_type": "����"
]),
([  "action": "$Nʹ����"+RED+"���Ʋ���"+NOR+"�������Ʒ�ס$n����·������бб������$l",
    "force": 240,
    "damage_type": "����"
]),
([  "action": "$N���ƻ��أ�����ʹһ�С�"+YEL+"������β"+NOR+"�����»ζ��Ż���$n��$l",
    "force": 250,
    "damage_type": "����"
]),
([  "action": "$Nʹ����"+YEL+"��Ծ��Ԩ"+NOR+"������$n��$l��������",
    "force": 260,
    "damage_type": "����"
]),
([  "action": "$Nʩ��һ�С�"+YEL+"�����"+NOR+"�������Ʋ�������������$n��$l",
    "force": 270,
    "damage_type": "����"
]),
([  "action": "$Nʹ����"+CYN+"��Ծ��Ԩ"+NOR+"�������η���˫�Ʋ���һ����$n��$l����",
    "force": 160,
    "damage_type": "����"
]),
([  "action": "$N˫������ʹ����"+CYN+"ʱ������"+NOR+"����$n��������",
    "force": 300,
    "damage_type": "����"
]),
([  "action": "$N���һ����˫��ʹ����"+CYN+"�𾪰���"+NOR+"��������һ�а����$n",
    "force": 330,
    "damage_type": "����"
]),
([  "action": "$N�Ż��󿪣�һ�С�"+GRN+"��˪����"+NOR+"����$n��$l��ȥ",
    "force": 350,
    "damage_type": "����"
]),
([  "action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С�"+HIM+"��ս��Ұ"+NOR+"������$n��$l",
    "force": 360,
    "damage_type": "����"
]),
([  "action": "$Nʹ����"+RED+"��������"+NOR+"����˫�������������$n��$l",
    "force": 380,
    "damage_type": "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 180;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ʮ���Ʊ�����֡�\n");
   if ((int)me->query("max_neili")<500)
        return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("xianglong-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping ran_action;
    int level = me->query_skill("xianglong-zhang",1);
        if (me->query_temp("sum_power"))
        return ([  "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ����"+RED+"�����л�"+NOR+"������$n��$l",
                    "damage": level*6,
                    "attack": level*2,
                    "dodge": 0 - 5 * level,
                    "damage_type": "����",
                ]);
    else{
        ran_action=action[random(sizeof(action))];
        ran_action["dodge"]= 0 - level;
        ran_action["damage"]= level;
        ran_action["attack"]= level/2;
        }
    return ran_action;
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 300)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 2000)
        return notify_fail("�����������������ʮ���ơ�\n");
    me->receive_damage("qi", 60);
    me->add("neili", -30);
    return 1;
}
void do_interlink(object me, object victim)
{
    int skill_level=me->query_skill("xianglong-zhang",1);
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return;
        if (me->is_fighting(victim) && victim->is_fighting(me))
        if (random(skill_level)>200 && me->query("neili")>5000){
        me->add("neili",-random(4500)-500);
          me->set_temp("sum_power",1);
          message_vision(HIY+"\n$N�������˿��������һ�����ѽ���ʮ���Ƶľ�������˫��֮�У�\n"
          +"ɲ�Ǽ�ֻ��������������ɳ��ʯ�����Ϊ֮��ɫ....\n"+NOR,me);
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
          me->delete_temp("sum_power");
        }  
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

