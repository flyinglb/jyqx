// �߼�����  by wyz
// 8.5
#include <combat.h>
inherit SKILL;
mapping *action = ({
([  "action":"$N��$w����Ĵָ������һ����һ�С�"+MAG+"�ɻ����"+NOR+"��$w������˿˿��������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : MAG "�ɻ����" NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
 ]),
([  "action":"$N����һ��һ�С�"+HIW+"ѩ������"+NOR+"��$w����ѩ�����ƻ�ʵ������$n��$l",
    "force" : 180,
    "lvl" : 40,
    "skill_name" : HIW "ѩ������"NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([  "action":"$N���һ��һ�С�"+BLU+"Ǭ��һ��"+NOR+"������$wͻȻ�������",
    "force" : 180,
    "lvl" : 80,
    "skill_name" : BLU "Ǭ��һ��" NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([  "action":"$N���μӿ�һ�С�"+RED+"޹�����"+NOR+"��$w����һ������$n��$l",
    "force" : 180,
    "lvl" : 120,
    "skill_name" : RED "޹�����" NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([  "action":"$NͻȻ����һԾ����һ��һ�С�"+YEL+"��ӫ����"+NOR+"��,$w����һ������$n��$l",
    "force" : 180,
    "lvl" : 160,
    "skill_name" : YEL "��ӫ����" NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([  "action":"$N���첻����һ�С�"+HIW+"��������"+NOR+"��,$w�ڰ���л���һ��Բ������$n��$l",
    "force" : 180,
    "lvl" : 200,
    "skill_name" : HIW "��������" NOR,
    "damage_type":"����",
    "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});
int valid_enable(string usage) { return usage == "throwing"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
      if (me->query_skill("throwing",1) <= me->query_skill("mantianhuayu",1))
      return notify_fail("��Ļ����������޷���������ļ��ɣ�\n");
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
    
    level   = (int) me->query_skill("mantianhuayu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    if ((int)me->query_temp("mantianhuayu")>0)
        return (["action": BOLD "һ"+weapon->query("unit")+"$w"+BOLD+"����$n"+BOLD+"��$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"����",
                 "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                ]);
    return a_action;

}

int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 35 )
        return notify_fail("�����������������û�а취��ϰ���컨�ꡣ\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "throwing")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "throwing")
        return notify_fail("��װ�����������ԡ�\n");
    me->receive_damage("qi", 30);
    me->add("force", -20);
    me->add_temp("pratice_throwing",1);
    if (me->query_temp("pratice_throwing") > me->query_skill("mantianhuayu",1)/20 ){
           if( (int)ob->query_amount()==1 ) {
                   ob->unequip();
                   tell_object(me, BOLD "\n���" + ob->query("name") + "�����ˣ�\n\n"+NOR);
           }
           ob->add_amount(-1);
           me->delete_temp("pratice_throwing");
    }
    write("�㰴����ѧ����һ�����컨�ꡣ\n");
    return 1;
}

void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    skill=me->query_skill("mantianhuayu", 1);
    if (random(skill)>250){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("��"+enemy[i]->name());
        message_vision(BOLD+"$N����Ծ������һ�ӣ���"+weapon->query("unit")+weapon->name()+"ͬʱ����"+all_enemy+"��\n\n" NOR,me);
        me->set_temp("mantianhuayu",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(60*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_QUICK);
                     }
                }else break;
        }
    me->delete_temp("mantianhuayu");
    }
}
