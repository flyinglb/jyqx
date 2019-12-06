// referee.c

inherit NPC;

void create()
{
	set_name("��ƽ��", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{     
	object ob1, ob2;
	ob1 = this_player();

	if( !arg || arg=="" ) return 0;

	if ( this_object()->query_temp("busy") ) 
		return notify_fail("ÿ��ֻ�������˲μӱ��䡣\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
		return notify_fail("�����˭�Ȼ���\n");

	remove_call_out("check");
	call_out("check",0, ob1, ob2);

	remove_call_out("fighting");
	call_out("fighting",2, ob1, ob2);
}

void fighting(object ob1, object ob2)
{
	ob1->fight_ob(ob2);
	ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
	this_object()->set_temp("busy",1);
	command("chat ������" + ob1->query("name") 
		+ "��" + ob2->query("name") + "��ʼ������գ�\n");
	call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
	object ob;

	if(ob1->is_fighting()) 
	{
		call_out("observe",1,ob1,ob2);
		return 1;
	}

	if (ob1->query("qi")*100/ob1->query("max_qi") > 50 ) 
	{
		command("chat " + ob1->query("name") 
			+ "����սʤ" + ob2->query("name") + "��\n");
		ob = new("clone/money/silver");
		ob->move(ob1);
	}
	else
	{
		command("chat " + ob2->query("name") 
			+ "����սʤ" + ob1->query("name") + "��\n");
		ob = new("clone/money/silver");
		ob->move(ob2);
	}
	
	this_object()->delete_temp("busy");
	return 1;

}
