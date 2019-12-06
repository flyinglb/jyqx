// meng-zhu.c ��������
// modified by wind

#include <ansi.h>

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "meng-zhu"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
	return MENGZHU;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("κ��˫", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
	set("title", "��������" );
	set("gender", "����" );
	set("age", 40);
      set("long","�������۾����֣��������£�����պյĵ�������������\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("shen_type", 0);

	set("no_clean_up",1);
       set("no_get",1);
	set("combat_exp", 500000);

	set_skill("force",  100); 
	set_skill("unarmed",100);
	set_skill("sword",  100);
	set_skill("dodge",  100);
	set_skill("parry",  100);

	set("weapon", "/d/shaolin/obj/changjian");
	set("armor", "/d/city/obj/cloth");

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();        
	}
	else {
		set("id", "mengzhu");
		set_name(query("name"), ({ query("id") }));
		setup();
//              if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
//                if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear(); 
}
}

void init()
{

//        add_action("do_recopy",  "recopy");
//         add_action("do_recover", "recover");
	add_action("do_kill", "kill");

}

int do_kill()
{
	object ob;
	int i;

	command("say ����ı���������������ǳ������ı��ӵ��ˣ���");
	command("say ���°�����ʿ���ڣ�");
	
	message_vision("���ܵİ�����ʿȺ���$N����������\n", this_player());

	for(i=0; i<4; i++) {
		if( objectp( ob = present("wei shi " + (i+1), environment(this_object())) ) )
				 ob->kill_ob(this_player());	
		else	this_object()->kill_ob(this_player());		
	}

	return 1;
}

int accept_fight(object ob)
{
	object me  = this_object();
		
	if ( me->query("winner") == ob->query("id") ) 
{
            remove_call_out("do_copy");
             call_out("do_copy", 1, me, ob);
		return notify_fail("������Լ���ʲô�ܣ���\n");
}

	if (wizardp(this_player()))
		return notify_fail("��ʦ����������֮λ��\n");

	if ( me->is_fighting() ) 
		return notify_fail("�Ѿ�����������ս����������\n");

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}

int checking(object me, object ob)
{

//        object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say ��Ȼ��������ϲ���Ϊ��������������\n");
		command("chat �������������ǳ���������ǰ�ˣ�һ�����˻����ˣ�\n");
		command("chat ��ϲ" + ob->query("name") + "���ƾ�Ϊ��������������\n");
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڵ��������г���ͷ�� !\n");
		return 1;
	}

	return 1;  
}

int do_copy(object me, object ob)
{
	object ob1, ob2;
//        string mengzhu, shangshan, fae;
        string shangshan, fae;

	seteuid(getuid());

        me->set("hunmi",0);
	me->set("winner", ob->query("id"));
	me->add("generation", 1);	

	me->set("name",  ob->query("name") );
	
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", HIR + me->query("title") + NOR + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
        ob->set_temp("apply/short", ({me->short()}));
// --record which mengzhu generataion this player got-------by ReyGod
// = better to place this checking when players login.
     ob->set("mengzhu_gen",me->query("generation"));
	
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wulin mengzhu)");
	me->delete("title");

	if(!( ob1 = find_living("shangshan")) )
	ob1 = load_object("/clone/npc/shang-shan");
	shangshan = ob1->query("winner");

	if(!( ob2 = find_living("fae")) )
	ob2 = load_object("/clone/npc/fa-e");
	fae = ob1->query("winner");

	if( ob->query("id") == shangshan ) {
		rm( ob1->query_save_file() + __SAVE_EXTENSION__ );
		destruct(ob1);
	}
	else  if( ob->query("id") == fae ) {
                rm( ob2->query_save_file() + __SAVE_EXTENSION__ );
		destruct(ob2);
	}

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_recopy(object me, object ob)
{
	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");;

	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", HIR + me->query("title") + NOR + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short()}));
// --record which mengzhu generataion this player got-------by ReyGod
// = better to place this checking when players login.	
      ob->set("mengzhu_gen",me->query("generation"));


	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wulin mengzhu)");
	me->delete("title");

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_clone(object me, object ob)
{
	object *inv, new1;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop/damage") > 100 
		||  inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	save();

	tell_object(ob, "״̬������ϡ�\n");

	new1 = new("/clone/npc/meng-zhu");
	new1->move("/d/taishan/fengchan");
	destruct(me);

	return 1;
}

int do_recover()
{
	object me, ob;
	mapping skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");;

/* delete and copy skills */

	if ( mapp(skill_status = ob->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			ob->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			ob->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* copy combat exp values */

	ob->set("combat_exp", me->query("combat_exp"));

	write("״̬��Ԫ��ϡ�\n");

	return 1;
}

