// laoniansengren.c
inherit NPC;
inherit F_DEALER;

void init();
void greeting(object ob);
string ask_me();
void create()
{
	set_name("����ɮ��", ({ "laonian sengren", "seng", "sengren" }) );
	set("gender", "����" );
	set("age", 80);
	set("long","���������ƹ��̻��ɮ�ˡ�\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "��ɮ");
	set("vendor_goods", ({
		"/d/tianlongsi/obj/xiang",
	}));
	set("inquiry" ,([
		"������" : (:ask_me():),
	]));
	setup();
	carry_object("/d/xueshan/obj/c-jiasha")->wear();
}

void init()
{	
	object ob; 
	ob = this_player();
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "����ɮ��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "��������ɡ�\n");
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp2"))
		{
		me->set_temp("marks/ask_temp3",1);
		return "��ʧ�Ե����������ҿ���һ����Ӱ���������ˡ�\n";
		}
	else
		return "�����˵�˵�ʲô����\n";
}

