// tiezhang-zhangfa ���ư� �����Ʒ�
// by zqb
//update by cool 981010
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����һ������һ�С��ƴ����¡����Բ����������򣬵�ʱ��$n��������б��",
        "dodge": 5,
        "force": 200,
        "parry": 40,
        "lvl": 0,
        "damage_type": "����"
]),
([      "action": "$Nʹһ�С���ˮ�����������ƶ�Ȼ�����쳤���ұۣ��ɿ��һ��������ն��$n��$l",
        "dodge": 10,
        "force": 260,
        "parry": 35,
        "lvl": 0,
        "damage_type": "����"
]),
([      "action": "$NͻȻʹһʽ�����ƻ��衹��˫��������һ��һ����裬����һ����ת�����ˡ� ",
        "dodge": 15,
        "force": 300,
        "parry": 30,
        "lvl": 10,
        "damage_type": "����"
]),
([      "action": "$Nһ�С�����Ǭ�������͵ز���������ұ��������¼���������Ĵ������ָ��Ȧ�͵�$n��$l",
        "dodge": 20,
        "force": 280,
        "parry": 25,
        "lvl": 20,
        "damage_type": "����"
]),
([      "action": "$Nһ�С����ո��¡�������һ��һ�գ�һ����˿��������һ��֮�䣬һ�������ޱȵ������Ŷ�Ȼ������",
        "dodge": 25,
        "force": 320,
        "parry": 20,
        "lvl": 30,
        "damage_type": "����"
]),
([      "action": "$N���б���һʽ������Ϊ������˫�ƺ���г�����Ե�ŵݳ������غ�Х֮��������",
        "dodge": 20,
        "force": 350,
        "parry": 15,
        "damage": 10,
        "lvl": 40,
        "damage_type": "����"
]),
([      "action": "$Nһ�С����޵����������ƴ�Ȧ����������СȦ�������������������һ��֮�£�����$n��$l",
        "dodge": 25,
        "force": 400,
        "parry": 10,
        "damage": 15,
        "lvl": 50,
        "damage_type": "����"
]),
([      "action": "$Nһ�С���ָ��ɽ������һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��ա�",
        "dodge": 30,
        "force": 450,
        "parry": 5,
        "damage": 20,
        "lvl": 60,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���һ�������м��ɶ�������$nֱ�˶��£������б������ء���һ���̶���Х��",
        "force": 540,
        "parry": 10,
        "dodge": 40,
        "damage": 30,
                 "lvl": 100,
        "damage_type": "����"
                ]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
                  int i,level,lev;
        level = (int) me->query_skill("tiezhang-zhangfa",1);
                lev   = (int) me->query_skill("guiyuan-tunafa",1);
        
        if (me->query_temp("tzzf") && me->query("jiali") < 50 )
        me->set("jiali",50);
        
          for(i = sizeof(action); i > 0; i--) {
                                 if(level > action[i-1]["lvl"]) {
                               if (me->query_temp("tzzf")) {                
                    return ([  
                    "action" : WHT+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                    "force" : action[NewRandom(i, 20, level/5)]["force"]+random(30),
                    "dodge":action[NewRandom(i, 20, level/5)]["dodge"],
                    "damage": level/4+random(lev/5),
                    "lvl" : action[NewRandom(i, 20, level/5)]["lvl"],
                    "weapon" : "�Ƶ�",
                    "damage_type" : random(2)?"����":"����",
                    ]);
               } else return action[NewRandom(i, 20, level/5)];
                           }
                           }
}


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʒ�������֡�\n");
        if ((int)me->query_skill("guiyuan-tunafa", 1) < 30)
                return notify_fail("��Ĺ�Ԫ���ŷ���򲻹����޷��������Ʒ���\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("���������Ϊ�������޷��������Ʒ�");
        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("������������������Ʒ���\n");
        if (me->query_skill("tiezhang-zhangfa", 1) < 50)
                me->receive_damage("jing", 20);
        else
                me->receive_damage("jing", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lev;
//        string msg;
        object weap;
        weap = victim->query_temp("weapon");
        lev =me->query("tiezhang-zhangfa");

        if( (me->query("neili") > 1000)&& (victim->query_temp("weapon"))
                                            && (me->query_temp("tzzf"))
                         && (random(me->query_str()) > victim->query_str()/2) )
                 {      
                                      if (random((int)weap->query("rigidity"))<3)
                        {
                        message_vision(HIW "$N�����絶��������ʮ���£�ֻ������ž����һ����$n���е�" + weap->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, me, victim );
                        weap->move(environment(me));
                        weap->set("name", "�ϵ���"+weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        } else {
                        message_vision(HIW "$N�����絶��������ʮ���£�ֻ������������һ����$n���е�" + weap->name()
                                + "���������䵽���ϣ�\n" NOR, me,victim );
                        weap->move(environment(me));
                                                }
                                                victim->reset_action();
                        me->add("neili", -100);
                        return 1;
                 }
  
       
}


