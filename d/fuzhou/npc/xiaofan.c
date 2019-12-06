// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "seller" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("inquiry", ([
		"������" : "����Ҳ�����˾��ӣ���ô�������\n",
	]) );
	set("vendor_goods", ({
		"/d/village/npc/obj/bottle",
		"/d/village/npc/obj/egg",
		"/d/city2/obj/budai",
		__DIR__"/obj/qidan",
	}) );
	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
	object ob;
        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
void greeting(object ob)
{
        if (ob->query("gender")!="Ů��")
                say("С��ߺ�ȵ��������裬�����裬һҹ��˯�ٹ��\n");
        return;
}
