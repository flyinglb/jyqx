// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�°���", ({ "chen apo", "chen", "apo" }));
	set("title", "�ӻ����ϰ���");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "Ů��");
	set("age", 55);
	set("long",
		"�°��žþ�Ȫ�ݳǣ���˵������ʱ���м��ַ��ϣ������ھ�\n"
		"��ʱ������ͷ�����ϻ�׷�������\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
                "������" : "���������ǿ����ǻ���һ�����������ţ�����\n",
                "name" : "�����ҷ���ճ¡����ְ�����\n",
                "here" : "Ȫ���Ǹ��ۿڣ����д����˺ܶࡣ\n",
	]));
	
	set("vendor_goods", ({
		"/d/quanzhou/obj/xiuhua",
		"/d/quanzhou/obj/flower_shoe",
                "/d/quanzhou/obj/pink_cloth",
                "/d/city/obj/goldring",
                "/d/city/obj/necklace",
	}));

	setup();
   //carry_object("/d/city/obj/flower_shoe")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("�°���Ц���е�˵�����˿�������\n");
		break;
	case 1 :
		say("�°���˵��������ģ���Ҫ��ʲ��\n");
		break;
	}
}
