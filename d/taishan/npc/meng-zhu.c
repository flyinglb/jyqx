// meng-zhu.c ��������

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
	set("combat_exp", 500000);

	set_skill("force",  100); 
	set_skill("unarmed",100);
	set_skill("sword",  100);
	set_skill("dodge",  100);
	set_skill("parry",  100);

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();        
	}
	else {
		set("id", "mengzhu");
                set_name(query("name"), ({ query("id") }));
		setup();
	}
}

void init()
{
	object me = this_object();

	add_action("do_recopy", "recopy");
	add_action("do_save", "saveme");
		
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));
}

int do_save()
{
	return save();
}

int accept_fight(object ob)
{
	object me  = this_object();
		
	if ( me->query("winner") == ob->query("id") ) 
		return notify_fail("������Լ���ʲ��ܣ���\n");

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
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say ��Ȼ��������ϲ���Ϊ��������������\n");
//		command("chat �������������ǳ���������ǰ�ˣ�һ�����˻����ˣ�\n");
//		command("chat ��ϲ" + ob->query("name") + "���ƾ�Ϊ��������������\n");
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
	me->set("winner", ob->query("id"));
	me->add("generation", 1);	

	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + me->query("id") + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short()}));

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

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short()}));

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_clone(object me, object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

/* delete and copy skills */

	skill_status = me->query_skills();
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->delete_skill(sname[i]);
	}

	skill_status = ob->query_skills();
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i]);
		}
	}

	map_status = ob->query_skill_map();
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {;
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i]);
		}
	}

	prepare_status = ob->query_skill_prepare();
	pname  = keys(prepare_status);

	for(i=0; i<sizeof(prepare_status); i++) {
		me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
			inv[i]->unequip();
			me->set("weapon", 0);
		}
		if( inv[i]->query("armor_prop") && inv[i]->query("equipped") ) {
			inv[i]->unequip();
			me->set("armor", 0);
		}
	}

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop") && inv[i]->query("weapon_prop/damage") <= 100
		&&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		if( inv[i]->query("armor_prop") && inv[i]->query("armor_prop/armor") <= 100
		&&  inv[i]->query("equipped") ) {
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

	return 1;
}
