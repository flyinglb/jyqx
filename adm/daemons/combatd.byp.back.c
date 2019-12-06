// combatd.c
//modified by wind

#pragma save_binary
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_DBASE;
object *player;
int userno;

mapping limb_damage = ([
// �������岿λ
        "ͷ��"  :   100,
        "����"  :   90,
        "�ؿ�"  :   90,
        "����"  :   80,
        "���"  :   50,
        "�Ҽ�"  :   55,
        "���"  :   40,
        "�ұ�"  :   45,
        "����"  :   20,
        "����"  :   30,
        "����"  :   60,
        "С��"  :   70,
        "����"  :   40,
        "����"  :   50,
        "���"  :   35,
        "�ҽ�"  :   40,
//  �������岿λ
        "����"  :   80,
        "ǰ��"  :   40,
        "���"  :   50,
        "�Ȳ�"  :   40,
        "β��"  :   10,
        "���"  :   50,
        "צ��"  :   40,
]);

string *guard_msg = ({
    CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
    CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
    CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
    CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
    CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});
string *catch_hunt_msg = ({
    HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
    HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
    HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
    HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
    HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
    HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
    HIW "$N�ȵ�����$n�����У���\n" NOR,});
string *winner_msg = ({
    CYN "\n$N������Ц������˵���������ˣ�\n\n" NOR,
    CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
    CYN "\n$N������Ц��˫��һ����Ц��˵�������ã�\n\n" NOR,
    CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
    CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
    CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
    CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});
void create()
{
    seteuid(getuid());
    set("name", "ս������");
    set("id", "combatd");
}
string damage_msg(int damage, string type,object ob)
{
    string str;
    int qi=ob->query("qi");
//  return "��� " + damage + " ��" + type + "��\n";
    if( damage == 0 ) return "���û������κ��˺���\n";
    if (qi>0){
        damage=damage*100;
        damage /= qi;
    }else
        damage=120;
    switch( type ) {
    case "����":
    case "����":
        if( damage < 5 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
        else if( damage < 10 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
        else if( damage < 20 ) return "������͡���һ������һ���˿ڣ�\n";
        else if( damage < 40 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
        else if( damage < 80 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
        else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
        break;
    case "����":
        if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
        else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
        else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
        else if( damage < 60 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
        else if( damage < 80 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
        else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
        break;
    case "����":
        if( damage < 5 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
        else if( damage < 10 ) return "�����$p��$l���һ�����ࡣ\n";
        else if( damage < 25 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
        else if( damage < 40 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
        else if( damage < 50 ) return "������项��һ����$n����������\n";
        else if( damage < 60 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
        else if( damage < 80 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
        else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
        break;
    case "����":
        if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
        else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
        else if( damage < 30 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
        else if( damage < 40 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
        else if( damage < 60 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
        else if( damage < 75 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
        else if( damage < 90 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
        else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
        break;
    default:
        if( !type ) type = "�˺�";
        if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
        else if( damage < 20 ) str = "��������΢��";
        else if( damage < 30 ) str = "������һ��";
        else if( damage < 50 ) str = "������һ������";
        else if( damage < 60 ) str = "��������Ϊ���ص�";
        else if( damage < 70 ) str = "�������൱���ص�";
        else if( damage < 80 ) str = "������ʮ�����ص�";
        else if( damage < 90 ) str = "�����ɼ������ص�";
        else str =  "�����ɷǳ����µ�����";
        return str + type + "��\n";
    }
}
string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
    if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
    if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
    if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
    if( ratio > 40 ) return RED "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
    if( ratio > 30 ) return RED "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
    if( ratio > 20 ) return RED "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
    if( ratio > 10 ) return HIR "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    if( ratio > 5  ) return HIR "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
    return HIR "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}
string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
    if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
    if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
    if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
    if( ratio > 40 ) return RED "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
    if( ratio > 30 ) return RED "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
    if( ratio > 20 ) return RED "�������Ѿ����������ˡ�" NOR;
    if( ratio > 10 ) return HIR "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    return HIR "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}
varargs void report_status(object ob, int effective)
{
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
    if( effective )
	{
        message_vision( "( $N" + eff_status_msg(
            (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
            + " )\n", ob);
// �����ֳ�ת�� start
		if ((string)environment(ob)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], "( " + ob->name() + eff_status_msg(
			(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n");
// �����ֳ�ת�� end
	}
    else
	{
        message_vision( "( $N" + status_msg(
            (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
            + " )\n", ob);
// �����ֳ�ת�� start
		if ((string)environment(ob)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], "( " + ob->name() + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n");
// �����ֳ�ת�� end
	}
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power;

    if( !living(ob) ) return 0;
    if (ob->over_encumbranced())    return 0;
    status=1;
    if (ob->query("max_qi")<1 || ob->query("max_jing")<1) return 1;
    else {
        status=(ob->query("eff_qi")*10)/ob->query("max_qi");
    status=status*(ob->query("jing")*10)/ob->query("max_jing");
    }
    if (status<1)   return 1;
    level = ob->query_skill(skill);
    switch(usage) {
        case SKILL_USAGE_ATTACK:
            level += ob->query_temp("apply/attack");
            if (ob->is_fighting())
                level +=  ob->query_temp("fight/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level += ob->query_temp("apply/defense");
            if (ob->is_fighting())
                level += ( ob->query_temp("fight/dodge")+ ob->query_temp("fight/parry"));
            break;
    }
    if( !level || level<1){
        power=(int)ob->query("combat_exp");
        if (power>10000000){
            power /= 100;
            power*=status;
        }else{
            power *= status;
            power/=100;
        }
        return  power;
    }
    // here need a modification later
     power=level*level;
    if (usage == SKILL_USAGE_ATTACK){
        if(!ob->is_ghost()) {
        if (skill=="unarmed")
        power*=(ob->query_str() + ob->query_temp("str")-ob->query("jiali"));
        else
        power*=(ob->query("str") + ob->query_temp("str")+ob->query_skill(skill,1)/10);
        power=(power/3)*2;
        }// add Byp@MX 
    }else
        power*=(ob->query_dex()*2/3 + ob->query_temp("dex"));

    power += (ob->query("combat_exp")*15);
    if (power>10000000){
        power /= 100;
        power*=status;
    }else{
        power *= status;
        power/=100;
    }
    if (level>2000 && power<0) return 2100000000;
    return power;
}
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your, action,prepare;
    string limb, *limbs, result,dodge_msg;//,parry_msg;
    string attack_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp;
    int damage, damage_bonus, defense_factor;
    int cost;
    int wounded = 0;
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
    

 //add by wind,���Խ�����npcֻ���򲻻���
        if (me->is_ghost()) { me->die(); return 1; }
        if (!living(me)) return 1;
        if(environment(me)->query("no_fight_npc")&&userp(me)&&!userp(victim)) 
        return 0;
        if( environment(me)->query("no_fight") ) return 0;
   
    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    //
    // (0) Choose skills.
    //
    me->delete_temp("fight");
    victim->delete_temp("fight");

	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
 
    
//    if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
//    else attack_skill = "unarmed";
    
    //
    // (1) Find out what action the offenser will take.
    //
    me->reset_action();
    action = me->query("actions");
    if( !mapp(action) ) {
        me->reset_action();
        action = me->query("action");
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                    me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }
/*    if (stringp(me->query_temp("action_msg"))){
        result = "\n" + (string)me->query_temp("action_msg")+ action["action"] + "��\n";
        me->delete_temp("action_msg");
    }else
        result = "\n" + action["action"] + "��\n";
*/

	if (me->query_temp("action_flag") == 0)
          {
   if (stringp(me->query_temp("action_msg"))){
        result = "\n" + (string)me->query_temp("action_msg")+ action["action"] + "��\n";
        me->delete_temp("action_msg");
    }else
        result = "\n" + action["action"] + "��\n";
          }
	else
		result = "\n" + "������"+action["action"] + "!\n"; 

    //
    // (2) Prepare AP, DP for checking if hit.
    //
    limbs = victim->query("limbs");
    limb = limbs[random(sizeof(limbs))];
    
    // ���¿�����query_xxxx_msg�У�������ʽ���������,
    //����,victim->set_temp("fight/dodge",100)
    // ���,Ӧ���ڼ���ǰ�Ƚ��е���
    dodge_skill = me->query_skill_mapped("dodge");
    if( !dodge_skill ) dodge_skill = "dodge";
        dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,me);    
    dodge_skill = victim->query_skill_mapped("dodge");
    if( !dodge_skill ) dodge_skill = "dodge";
        dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim);    
    if (!dodge_msg || dodge_msg=="")
        dodge_msg = SKILL_D("dodge")->query_dodge_msg(limb,victim);    
    parry_skill = victim->query_skill_mapped("parry");
    if( !parry_skill ) parry_skill = "parry";
    //parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
//    if (!parry_msg || parry_msg=="")
//        parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);
    
    // --------------------------------------------------------
    // �������ӹ�����ʽ�����⹥��
    if (intp(action["dodge"]))
        victim->add_temp("fight/dodge", action["dodge"]/15);
    if (intp(action["parry"]))
        victim->add_temp("fight/dodge", action["parry"]/15);
    if (intp(action["attack"]))
        me->set_temp("fight/attack", action["attack"]/10);
    // ---------------------------------------------------------
    
    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
    if (cost=sizeof(me->query_enemy())>1){
        me->delete_temp("fighting");
        if (cost>6) cost=6;
        ap /=cost;
    }
    if( ap < 1) ap = 1;
    if( victim->is_busy() )
        dp = skill_power(victim, "skill", SKILL_USAGE_DEFENSE);
    else
        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);

    if (cost=sizeof(victim->query_enemy())>1){
       victim->delete_temp("fighting");
        if (cost>6) cost=6;
        dp /=cost;
    }
    if (!victim->visible(me)) dp /= 10;
    
    if( dp < 1 ) dp = 1;
    cost=skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
    if (cost<1) cost=1;
     if (ap>0 && cost>0 && (ap+cost)<0) cost=2000000000-ap;
    if (!me->visible(victim)) { ap /= 10; cost /= 10; }
    //
    // (3) Fight!
    //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
    //     AP and DP are greater than zero, so we always have chance to hit
    //     or be hit.
    //
    if( random(ap + cost) < dp ) {      // Does the victim dodge this hit?
        result += dodge_msg;
        if( your["combat_exp"] < my["combat_exp"]+1000
                 && (ap+cost) > dp
        && (ap+cost) > dp
        && random(your["jing"]*100/your["max_jing"] + victim->query_int()) > 50 ) {
            your["combat_exp"] += 1+victim->query_int()/30;
            victim->improve_skill("dodge", random(victim->query_int()));
        }
        // This is for NPC only. NPC have chance to get exp when fail to hit.
        if( (ap < dp) && !userp(me) ) {
            if( random(me->query_int()) > 15 ) my["combat_exp"] +=1+ me->query_int()/30;
            me->improve_skill(attack_skill, random(me->query_int()));
        }
        damage = RESULT_DODGE;
    } else {
        //
        //  (4) Check if the victim can parry this attack.
        //
        if (intp(action["parry"]))
            victim->add_temp("fight/parry", action["parry"]);
        if( victim->is_busy() )
            pp = skill_power(victim, "skill", SKILL_USAGE_DEFENSE);
        else
            pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        if( victim->query_temp("weapon") ){
            if( !weapon ) pp *= 2;
        }else
            if( weapon ) pp /= 2;
        if (sizeof(victim->query_enemy())>1){
            pp-=pp*(sizeof(victim->query_enemy())/4);
        }
        if (!victim->visible(me)) pp /= 10;
        if( pp < 1 ) pp = 1;
        if( random(ap + cost)< pp ) {
//            result += parry_msg;
            if( your["combat_exp"] < my["combat_exp"]+1000
        && (ap+cost) > pp
                && random(your["jing"]*100/your["max_jing"] + victim->query_int()) > 50 ) {
                your["combat_exp"] +=1+ victim->query_int()/30;
                victim->improve_skill("parry", victim->query_int());
            }
            damage = RESULT_PARRY;
        } else {
            //
            //  (5) We hit the victim and the victim failed to parry
            //
            if (weapon) damage = weapon->query("weapon_prop/damage");
            damage += me->query_temp("apply/damage");
            damage = (damage + random(damage)) / 2;
            if( action["damage"] )
                damage += action["damage"] * damage / 100;
            damage_bonus = me->query_str();
            // Let force skill take effect.
            if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
                if( stringp(martial_skill = me->query_skill_mapped("force")) ) {
                    foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
                    if( stringp(foo) ) result += foo;
                    else if( intp(foo) ) damage_bonus += foo;
                }
            }
            if( action["force"] )
                damage_bonus += action["force"] * damage_bonus / 100;
            if( stringp(martial_skill = me->query_skill_mapped(attack_skill)) ) {
                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }
            // Let weapon or monster have their special damage.
            if( weapon ) {
                foo = weapon->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            } else {
                foo = me->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }
            if( damage_bonus > 0 )
                damage += (damage_bonus + random(damage_bonus))/2;
            if( damage < 0 ) damage = 0;
            // Let combat exp take effect
            defense_factor = your["combat_exp"];
            while( random(defense_factor) > my["combat_exp"] ) {
                damage -= damage / 3;
                defense_factor /= 2;
            }
            //
            //  (6) Inflict the damage.
            //
            if (!undefinedp(limb_damage[limb]))
            damage = (damage*limb_damage[limb]/100);

            if( stringp(martial_skill = victim->query_skill_mapped("force")) && (int)victim->query_temp("apply/armor_vs_force") ) {
                    foo = SKILL_D(martial_skill)->armor_ob(me, victim, damage,(int)victim->query_temp("apply/armor_vs_force"));
                    if( stringp(foo) ) {result += foo;  damage=0;}
                    else if( intp(foo) ) damage = foo;
                }
// npc���������
                foo = victim->weapon_ob(victim,me, damage);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage += foo;

            result += damage_msg(damage, action["damage_type"],victim);
            damage = victim->receive_damage("qi", damage, me );
            if( random(damage) > (int)victim->query_temp("apply/armor")
            && ( (me->is_killing(victim)) 
                && ((!weapon) && !random(4) || weapon && !random(2) )
                || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
            {
                // We are sure that damage is greater than victim's armor here.
                victim->receive_wound("qi",
                    damage - (int)victim->query_temp("apply/armor"), me);
                wounded = 1;
            }
             if (me->query_temp("sum_power"))
                victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);
            //
            //  (7) Give experience
            //
            if( your["combat_exp"]+1000 > my["combat_exp"]
                &&  (random(my["jing"]*100/my["max_jing"] + me->query_int()) > 30) ) {
                    my["combat_exp"] +=1+ me->query_int()/30;
                    if( my["potential"] - my["learned_points"] < 10*me->query_int() )
                        my["potential"] += 1;
                    me->improve_skill(attack_skill, random(me->query_int()));
            }
        	if( random(your["max_qi"] + your["qi"]) < damage ) {
					your["combat_exp"] += random(2);
					if( your["potential"] - 10*me->query_int() )
						your["potential"] += random(2);
                }
        }
    } 
    result = replace_string( result, "$l", limb );
    if( objectp(weapon) )
        result = replace_string( result, "$w", weapon->name() );
    else if( stringp(action["weapon"]) )
        result = replace_string( result, "$w", action["weapon"] );
    else if( attack_skill == "unarmed" ) 
        result = replace_string( result, "$w", "ָ��һ������" );
    //message_vision(result, me, victim );
        message_vision(result, me, victim,"fight");
    if(wizardp(me) && me->query("env/combat")) {
        if( damage > 0 )
            tell_object(me, sprintf( BOLD "my AP��%d��victim DP��%d��victim PP��%d���˺�����%d\n" NOR,
                (ap+cost)/100, dp/100, pp/100, damage));
        else
            tell_object(me, sprintf( BOLD "my AP��%d��victim DP��%d��victim PP��%d\n" NOR,
                (ap+cost)/100, dp/100, pp/100));
    }
    if( wizardp(victim) && victim->query("env/combat") ) {
        if( damage > 0 )
            tell_object(victim, sprintf( BOLD "victim AP��%d��my DP��%d��my PP��%d���˺�����%d\n" NOR,
                ap/100, dp/100, pp/100, damage));
        else
            tell_object(victim, sprintf( BOLD "victim AP��%d��my DP��%d��my PP��%d\n" NOR,
                ap/100, dp/100, pp/100));
    }
    if( damage > 0 ) {
        report_status(victim, wounded);
        if( victim->is_busy() ) victim->interrupt_me(me);
//modified by eatdami
        if( (!me->is_killing(victim->query("id"))) && 
        (!victim->is_killing(me->query("id"))) &&
        victim->query("qi")*2 <= victim->query("max_qi")) {
            me->remove_enemy(victim);
            victim->remove_enemy(me);
            if (me->query("family/family_name")!="������"
            && victim->query_temp("fighting")==me
            && me->query("family/master_id")==(string)victim->query("id")) {
                me->delete("family");
                me->set("title","��ͨ����");
                me->delete("class");
                victim->delete_temp("fighting");
                message_vision("$N����һЦ���治�������������ʤ������"+me->name(1)+"������Գ�ʦ�ˣ��Ӵ������Ż��ɣ�\n", victim);
            }else
            message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
// �����ֳ�ת�� start
		result = winner_msg[random(sizeof(winner_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// �����ֳ�ת�� end
            if( (victim->query("name") == "ͭ��")
            && (victim->query("id") == "tong ren") 
            && ((int)me->query_temp("fight_tongren") > 0) ) {
                me->add_temp("fight_tongren",-1);    
            }
        }
    }
    if( functionp(action["post_action"]) )
        evaluate( action["post_action"], me, victim, weapon, damage);
        else
        WEAPON_D->bash_weapon(me, victim, weapon, damage);
    // See if the victim can make a riposte.
    if( attack_type==TYPE_REGULAR
    &&  damage < 1
    &&  victim->query_temp("guarding") ) {
        victim->set_temp("guarding", 0);
        if( random(my["dex"]) < 5 ) {
            message_vision("$Nһ�����У�¶����������\n", me);
// �����ֳ�ת�� start
			if ((string)environment(me)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], me->name()+"һ�����У�¶����������\n");
// �����ֳ�ת�� end
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        } else {
            message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
// �����ֳ�ת�� start
			if ((string)environment(me)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], me->name()+"��"+victim->name()+"����ʧ�󣬳û�����������\n");
// �����ֳ�ת�� end
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
}
//  fight()
//
//  This is called in the attack() defined in F_ATTACK, which handles fighting
//  in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;
	string result;
    string skill_name;
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
    if( !living(me) || me->is_busy() ) return;
    if (!me->visible(victim)) return;
    if (environment(me)!=environment(victim) ) return;
    if (environment(me)->query("no_fight"))  return;
    
    // If victim is busy or unconcious, always take the chance to make an attack.
    if( victim->is_busy() || !living(victim) ) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        if ((random(me->query_int())>50 || random(10)<3) && victim->is_fighting(me)){
            me->set_temp("secondly_weapon",1);
            do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
            me->delete_temp("secondly_weapon");
        }
        if (living(victim)){
            if(  !objectp(ob=me->query_temp("weapon")))
                skill_name="unarmed";
            else skill_name=ob->query("skill_type");
            skill_name=me->query_skill_mapped(skill_name);
            if (stringp(skill_name)){
                me->set_temp("action_flag",1);
                SKILL_D(skill_name)->do_interlink(me, victim);
                me->set_temp("action_flag",0);
            }
        }

   // Else, see if we are brave enough to make an aggressive action.

    } else if( random( (int)victim->query_dex() * 2 ) < (int)me->query_dex() || random(10)<3) { 
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);  
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        if ((random(me->query_int())>50 || random(10)<2) && victim->is_fighting(me)){
            me->set_temp("secondly_weapon",1);
            do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
            me->delete_temp("secondly_weapon");
        }

        if(  !objectp(ob=me->query_temp("weapon")))
              skill_name="unarmed";
        else skill_name=ob->query("skill_type");
        skill_name=me->query_skill_mapped(skill_name);
        if (stringp(skill_name)){
            me->set_temp("action_flag",1);
            SKILL_D(skill_name)->do_interlink(me, victim);
            me->set_temp("action_flag",0);
        }
    } else if( !me->query_temp("guarding") ) {
        me->set_temp("guarding", 1);
        message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
// �����ֳ�ת�� start
		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// �����ֳ�ת�� end
        return;
    } else return;
}

//  auto_fight()
//
//  This function is to start an automatically fight. Currently this is
//  used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;
    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no 
    // aggressive callout wating here.
    if( me->query_temp("looking_for_"+type ) ) return;
    me->set_temp("looking_for_"+type, 1);
    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}
void start_berserk(object me, object obj)
{
    int shen,sb_shen;
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_berserk", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    if (me->query("marry")==obj->query("id")) return;
    message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);
    if( (shen < -50000 || sb_shen>100000) && me->query_per()>random(obj->query_per())*2 
    &&  !wizardp(obj) ) {
        message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
            + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
        me->kill_ob(obj);
        obj->fight_ob(me);
    } else {
        message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
            + "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",me, obj);
        me->fight_ob(obj);
        obj->fight_ob(me);
    }
}
void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_hatred", 0);
      if (!me->query("demogorgon") && !obj->query("demogorgon")  )
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    if (me->query("marry")==obj->query("id")) return;
    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
    obj->fight_ob(me);
}
void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_vendetta", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
    obj->fight_ob(me);
}
void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_aggressive", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
    obj->fight_ob(me);
}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
    object *target;
    int i;
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
    switch(event) {
        case "dead":
            message_vision(HIC "\n$N���ˡ�\n\n" NOR, ob);
// �����ֳ�ת�� start
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], "\n"+ob->name()+"���ڵ��������˼��£���һ�ţ��������������Ѫ�����ˡ�\n");
// �����ֳ�ת�� end
            break;
        case "unconcious":
            message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
// �����ֳ�ת�� start
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], "\n"+ob->name()+"����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n");
// �����ֳ�ת�� end
            break;
        case "revive":
            message_vision("\n$N���������۾��������˹�����\n\n", ob);
// �����ֳ�ת�� start
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], "\n"+ob->name()+"���������۾��������˹�����\n\n");
// �����ֳ�ת�� end
            if (sizeof(target=ob->query_killer())>0)
                for (i=0;i<sizeof(target);i++){
                  if (objectp(target[i]))
                    if (present(target[i],environment(ob))){
                        auto_fight(ob, target[i], "hatred");
                        return;
                    }
                break;
            }
    }
}
void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

int die_for(object victim)
{
    if (!userp(victim)) return 0;
        victim->add("DIED",1);
        victim->clear_condition();
        // Give the death penalty to the dying user.
        victim->add("shen", -(int)victim->query("shen") / 10);
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
        victim->delete("vendetta");
        victim->delete("bellicosity");
        if( victim->query("thief") )
            victim->set("thief", (int)victim->query("thief") / 2);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
            victim->add("potential",
                ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
        victim->skill_death_penalty();
        if (stringp(victim->query_temp("die_for"))){
            CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("%s%s���ˡ�", victim->name(1),victim->query_temp("die_for")));
            victim->delete_temp("die_for");
        }else
            CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("%s�������ˡ�", victim->name(1)));
}

void killer_reward(object killer, object victim)
{
	int bls;
	string vmark;
	mapping quest;
	int exp, pot, score, bonus,factor;
	string killer_master_id;

	// Call the mudlib killer apply.
	killer->killed_enemy(victim);
	killer_master_id=killer->query("family/master_id");

	if( userp(victim) ) {
		killer->add("PKS", 1);
		victim->clear_condition();
		// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
//modified by wind
                if((int)victim->query("combat_exp") / 50>20000)
		victim->add("combat_exp", -20000);
                else
		victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);                


		victim->delete("vendetta");
		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",
				((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		victim->skill_death_penalty();
// Add by jungu             
		if (userp(killer))
		write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) killed by %s(%s) on %s\n",
		victim->name(1), victim->query("id"),
		killer->name(1),killer->query("id"),ctime(time()) ));
// End of apprendence

		// Look for PKS 
		bls = 10;
		CHANNEL_D->do_channel(this_object(), "rumor",
// This line is modefied by Hop, 97.05.16
// After the modification, if you kill a player with mask on face, 
// the rumor channel will not display your real name. 
			sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(0)));
//			sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));
	} else {
		killer->add("MKS", 1);
		bls = 1;
	}

//If the victim is the killer's master
if(killer_master_id==(string)victim->query("id")){
//modified by wind
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s��ʦ��%s��%sɱ���ˡ�", killer->name(1),victim->name(1), killer->name(1)));
		killer->apply_condition("killer", 1000);
if(killer->query("combat_exp")>=1000000)
{
        if(killer->query("self_betrayer")>=5)
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s�Զ�߱ʦ��ʦ������Σ���Ϊ�������࣬��������ʦ�ˡ�\n", killer->name(1)));
        else
        {
		killer->delete("family");
		killer->set("title","ƽ��");
		killer->delete("class");
		destruct(victim);
                killer->add("self_betrayer",1);
	}
}
return ;
}

	if (userp(killer) && killer->query("combat_exp") < victim->query("combat_exp")) 
		killer->add("shen", -(int)victim->query("shen") / 10);

//by wind

	if (userp(killer))
	killer->add("shen", -(int)victim->query("shen") / 200);
        
// Player-killer will be wanted by soldiers, and if killer & victim are all players,
// the killer will gain some exp from victim. But it has some limit of cause.
	if (userp(victim) && userp(killer))
		killer->apply_condition("killer", 1000);

	if (userp(killer) && (((int)killer->query("combat_exp") * 2) < (int)victim->query("combat_exp") )
	&& userp(victim) && ((int)victim->query("combat_exp") >= 50000) )
		killer->add("combat_exp", (int)victim->query("combat_exp") / 30);
// End of appendence
	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

// add the quest reward here
 
	if (userp(victim))
	{
		return;
	}
	if( interactive(killer) && (quest = killer->query("quest"))
		&& ( (int)killer->query("task_time") >= time())
		&&(quest["quest"]==victim->query("name")))
	{
		tell_object(killer,"��ϲ�㣡���������һ������\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=victim->query("quest_factor");
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) killer->query("combat_exp");
		bonus += exp;
		killer->set("combat_exp", bonus);
		bonus = (int) killer->query("potential");
		bonus = bonus - (int) killer->query("learned_points");
		bonus = bonus + pot;
		if( bonus > 300) bonus = 300;
		bonus += (int)killer->query("learned_points");
		killer->set("potential", bonus );
		bonus = (int)killer->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
		killer->set("shen", bonus);
		tell_object(killer,HIW"�㱻�����ˣ�\n" +
        	chinese_number(exp) + "��ʵս����\n"+
        	chinese_number(pot) + "��Ǳ��\n" +
        	chinese_number(score)+"����\n"
			NOR	);
		killer->set("quest", 0 );
	}
}
