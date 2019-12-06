// xiaozei.c

inherit NPC;

void create()
{
	set_name("С��", ({ "xiao zei","xiao","zei" }) );
	set("gender", "����" );
	set("age", 15);
	set("long", "һ��Ц�����������С����\n");

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", 0);

	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);

	set("combat_exp", 20000);
	set("str", 27);
	set("kar", 100);
	set("thief", 0);
	set("force", 200);

	set("max_force", 200);
	set("force_factor", 2);

	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("stealing", 100);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"С��˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"С��������ش��˸���Ƿ��\n",
		"С������׽ס�����ϵ�ʭ�ӣ����: Сү����û�����⣬�����ǻ�ҧ! \n",
		(: random_move :)
	}) );
	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->present("gold_money")) command("hi");
	switch( random(5) )
	{
		case 0:
                       command("hehe " + ob->query("id"));
                       command("steal coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("steal changjian from " + ob->query("id"));	
                       command("wield changjian");	
                       command("drink jiudai");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("steal jitui from " + ob->query("id"));	
                       command("eat jitui");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
		command("smile");
		command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
		command("give 10 silver to " + me->query("id"));
	}
        else {
        	command("shake");
		command("say ���ֶ������Ҫ ! ��һ��ȥ !");
		command("give " + obj->query("id") + " to " + me->query("id"));
//		obj->move(this_player());
        }
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
