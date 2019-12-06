// xiaoer.c �Ƶ�С��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 20);
	set("long",
		"��λ��С����Ц�����æ���к����ˡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/baituo/obj/sherou",
		"/d/shaolin/obj/hulu",
	}));
	setup();
}

void init()
{
	object ob;

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
               {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��ƣ�ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "��������������������\n");
			break;
	}

}

