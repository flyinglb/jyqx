// fengqi.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "feng qi", "feng", "qi" }) );
	set("gender", "����" );
	set("title", "��¥�ϰ�" );
	set("age", 42);
	set("long",
"�����Ƿ����ϵ�Զ����ܣ�����Ӣ��¥���ƹ��书û��ʲô��Ϊ��ȴ���ǻ��顣\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "�߸�");
	set("vendor_goods", ({
		"/clone/food/jitui",
		"/clone/food/jiudai",
		"/clone/food/baozi",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "ؤ��" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "���������\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n���ߴ��һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/foshan/street4");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
		"���˴�Ӣ��¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
