// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;
int ask_wu();
void create()
{
	set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
        set("inquiry", ([
                "������" : (: ask_wu :),
        ]));

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}

/*
void init()
{
//	add_action("do_buy", "buy");
}
*/
int ask_wu()
{
	object ob;
	ob = this_player ( ) ;
message_vision("ƽһָ�������´�����$Nһ�£�ʲô�������ڣ���ʮ���ƽ�����\n",ob);
	ob->set_temp ("������" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("������"))
	{
        message_vision("ƽһָ��$N˵��ҽһ�ˣ�ɱһ�ˣ��Ϸ���Ǯ��\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 100000)
	{
		message_vision("ƽһָ����$N�����ڣ�\n" , who);
		this_player()->delete_temp("������" );
		obj=new(__DIR__"obj/shouwu");
		obj->move(this_player());
                call_out("dest",1,ob);
                return 1;
	}
        return 0;
}
void dest(object ob)
{
        if(!ob) return;
        ob->move(VOID_OB);
        destruct(ob);
}
