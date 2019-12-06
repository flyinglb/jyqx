// haojie.c
#include <ansi.h>;
inherit NPC;

int ask_back();
void create()
{
	set_name("̫������", ({ "hao jie", "jie" }));
	set("gender", "����");
	set("age", 25);
	set("long", "���ǹ���ׯ���µ���̫���ٸ���ƶ��̫�����ܡ�\n");
	set("combat_exp", 100000);
        set_skill("dodge", 50);
        set_skill("lingxu-bu", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("changquan", 50);
        map_skill("unarmed", "changquan");
        map_skill("parry", "changquan");
        map_skill("dodge", "lingxu-bu");
	set("shen_type", 1);
	set("chat_msg", ({
		"̫�����ܵ�����Ҫ�������͸�����....\n",
	}));
	set("inquiry", ([
		"����": (:ask_back:),
	]));
	setup();

	carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	tell_object(ob,"̫�����ܵ�������λ"+RANK_D->query_respect(ob)+"��Ҫ�������͸�����....��\n");
}

int ask_back()
{
	object ob = this_player();
	environment(ob)->delete("exits/out");
	message_vision("����Ⱥ������Ӧ������������ȥ�칦ඣ�\n", ob);
	message_vision("�������𷫣����������ׯ���С�\n", ob);
	tell_object(ob, CYN "���ʴ��ں�������ǰ�У���������.......\n" NOR ) ;
	call_out("rguiyun", 10 , ob );
	return 1 ;
}
void rguiyun( object ob )
{
	object ship, matou;
	if(!( ship = find_object("/d/guiyun/ship")) )
		ship = load_object("/d/guiyun/ship");
	if(!( matou = find_object("/d/guiyun/matou")) )
		matou = load_object("/d/guiyun/matou");
	tell_object(ob , "ս����һ����������п�������ͷ��\n" ) ;
	ship->set("exits/out", "/d/guiyun/matou" );
}
