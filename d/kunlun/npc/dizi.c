inherit NPC;
void create()
{
        set_name("����", ({ "di zi", "di" }));
        set("title", "������");
        set("long", 
                "���������书��һ�㡣\n");
        set("gender", "����");
        set("age", 21);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 22);
        set("dex", 28);
        set("per", random(15) + 10);
        set("no_xi", 1);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 50);
        set("max_neili", 50);
        set("jiali", 100);
        set("combat_exp", 5000);
        set("shen",0);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);

        create_family("������", 5, "����");

        setup();
        carry_object(__DIR__"obj/zhujian")->wield();
        carry_object("/clone/cloth/male2-cloth")->wear();
        
}
int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

//	if (me->query("damaged"))
//		return notify_fail("�����������̫���ˣ�\n");	
//
//	if (random(me->query("fight_times")) >= 10) {
//		me->set("damaged", 1);
//		return notify_fail("�����������̫���ˣ�\n");	
//	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("��ո����������������\n");		

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 300 + random(150), me);	

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
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}


