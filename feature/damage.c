// damage.c
// 98-9-11 netplay@CCTX
//modified by long
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater;

	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();
	set("hunmi",1);
        set("hunmi_last_time",time());
	message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
		this_object());
	this_object()->disable_player("");
	set("jing", 0);
	set("qi", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

void revive(int quiet)
{
        object env;
        remove_call_out("revive");
        while( environment()->is_character() || environment()->is_container() )
		this_object()->move(environment(environment()));
        this_object()->enable_player();
        set("hunmi",0);
        set("hunmi_last_time",0);
        env = environment();
        move(VOID_OB,1);
        move(env,1);
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		
		message("system", HIY "\n������������������֪��....\n\n" NOR,
			this_object());
	} else
		{set_temp("block_msg/all", 0);set("hunmi",0);}
}

void die()
{
	object corpse, killer;

	if( !living(this_object()) ) revive(1);
	if( wizardp(this_object()) && query("env/immortal") ) return;

        //��̨���䲻��
        if (file_name(environment(this_object())) == "/d/city/leitai")
        {
                message_vision(HIR "���ѷ�ʤ����������������\n" NOR, this_object());
                this_object()->remove_all_killer();
                all_inventory(environment())->remove_killer(this_object());
                if ( (int)this_object()->query("eff_jing") <0 ) this_object()->set("eff_jing",1);
                if ( (int)this_object()->query("jing") <0 ) this_object()->set("jing",1);
                if ( (int)this_object()->query("eff_qi") <0 ) this_object()->set("eff_qi",1);
                if ( (int)this_object()->query("qi") <0 ) this_object()->set("qi",1);
                return;
        }
	// Clear all the conditions by death.
	this_object()->clear_condition();
	COMBAT_D->announce(this_object(), "dead");
	
       if( objectp(killer = query_temp("last_damage_from")) &&file_name(environment(killer)) == file_name(environment(this_object())))
     {
                   this_object()->add("dietimes",1);
                this_object()->add("normal_die", 1);
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}
        else
        this_object()->add("dietimes",1);
	
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	{
		corpse->move(environment());
// �����õľ���ֵ
                corpse->set("combat_exp", this_object()->query("combat_exp"));
// ���������
                if (userp(this_player()))
                        corpse->set("userp", 1);
        }

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	if( userp(this_object()) ) {
		if (this_object()->is_busy())
			this_object()->interrupt_me();
		set("jing", 1);	set("eff_jing", 1);
		set("qi", 1);	set("eff_qi", 1);
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());//����ƺ�ûʲô��ѽ��
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
	int update_flag;
	mapping my;
	object ob=this_object();

//	if( this_object()->is_fighting() ) return -1;

	if (environment())
	if (environment()->is_chatting_room()) return -1;
	update_flag = 0;

	my = query_entire_dbase();

	if( (my["water"] > 0) && !wizardp(ob) ) {
	        my["water"] -= 1;
	        update_flag++; 
	}
	
	if( my["food"] > 0 ) {
	        if(!wizardp(ob)) {
	                my["food"] -= 1;
	                update_flag++; 
	        }
	        
	        if ( my["food"] == ob->max_food_capacity()*0.3 )
		        tell_object(ob,HIY "\n����ӹ���ֱ�У������óԵ㶫���ˡ�\n"NOR);
	        
	        if ( my["food"] == ob->max_food_capacity()*0.1 ) {
		        tell_object(ob,HIY "\n�����ֱ���ţ��Ͽ�Ե㶫���ɡ�\n"NOR);
		        ob->delete_temp("foods");
		}
	} else {
	        if (!ob->query_temp("foods")) {
	                tell_object(ob,HIR "\n�����ֱð���ǣ�ʵ���Ƕ���ס�ˡ�\n"NOR);
		        ob->set_temp("foods",10);
		}
	
		if ((int)ob->query_temp("foods") > 1)
		        ob->add_temp("foods",-1);
		else {
		        tell_object(ob,HIR "\n����ÿ�Ҫ���ˡ�������\n"NOR);  
			if (wizardp(ob)) {
			        tell_object(ob,HIY "�����������ɣ�ֻ��������һ�У������һ��ѺóԵ�\n"+
				"�ۣ����к�����Ү�����㻩�����¾ͳԹ��ˣ����������Ƕ����ˣ�\n"NOR);
			        ob->set("food",ob->max_food_capacity());
			        ob->set("water",ob->max_water_capacity());
			}else if ((int)ob->query("age")<15) {
			        tell_object(ob,HIY "������û�������ڡ��������ͳ�һ֧��ƿ�ݺݵ��������ڣ����úù����ˡ�\n"NOR);
			        ob->set("food",ob->max_food_capacity());ob->set("water",ob->max_water_capacity());
			}else {
			        if (userp(ob))
			                ob->unconcious();
			                ob->set_temp("foods",10);
			}
		}
		update_flag++; 
	}

	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
	
	my["jing"] += my["con"] / 3 + my["max_jingli"] / 10;
	
	if( my["jing"] >= my["eff_jing"] ) {
		my["jing"] = my["eff_jing"];
		if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"] ++; update_flag++; }
	} else update_flag++;

	my["qi"] += my["con"] / 3 + my["max_neili"] / 10;
	
	if( my["qi"] >= my["eff_qi"] ) {
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
	} else update_flag++;

	if( my["food"] < 1 && userp(this_object()) ) return update_flag;

/*
	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
		my["jingli"] += (int)this_object()->query_skill("dodge", 1) / 2;
		if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
		update_flag++;
	}
*/

        if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {//add Byp@MX
                int n = my["water"];
                if( n < my["food"] ) n = my["food"];
                my["jingli"] += n * 100 / ob->max_food_capacity() / 20;
                if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
                update_flag++;
        }

	if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
		my["neili"] += (int)this_object()->query_skill("force", 1) / 2;
		if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
		update_flag++;
	}

	return update_flag;
}
