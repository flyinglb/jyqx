// laoban.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ƹ��ϰ�", ({ "lao ban" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"��λ�ƹ��ϰ��������㣬��ͷ�����Ŷ���Ц�š�\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("no_get", "1");
	set("vendor_goods", ({
		__DIR__"obj/gourou",
		__DIR__"obj/gouroutang",
		__DIR__"obj/map",
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
			say( "�ƹ��ϰ�����˵������ô����죬���빷����������ů�����ӵģ�\n");
			break;
		case 1:
			say( "�ƹ��ϰ���˴��֣�˵������λ" + RANK_D->query_respect(ob)
				+ "������󲹰��������ɡ�\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n�ƹ��ϰ���һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/guanwai/nancheng");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
		"���˴��������һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
