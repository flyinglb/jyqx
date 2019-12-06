// oldman.c
// by victori
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
	set_name("��������", ({ "old man", "oldman"}) );
	set("gender", "����" );
	set("age", 64);
	set("long",
		"һ���뷢�԰׵����ߣ��������壬�����⡣\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set("title", "����");
	set_skill("dodge", 120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("force",120);
	set_skill("hammer", 120);
	set_skill("duji", 120);
	set_skill("sword",120);
	set_skill("literate", 50);
	set_skill("wudu-yanluobu", 120);
	set_skill("qianzhu-wandushou", 120);
	set_skill("wudu-shengong", 120);

        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "qianzhu-wandushou");
	set("vendor_goods", ({
//	       __DIR__"obj/jiedudan",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
       add_money("silver",30);
set("inquiry", ([
"�Ĵ�": (: ask_me :),
"����": (: ask_me :),
"�տ�": (: ask_me :),
]) );
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
	switch( random(3) ) {
		case 0:
			say( "������������Ц������λ" + RANK_D->query_respect(ob)
				+ "�������������Ķ������\n");
			break;
		case 1:
			say( "�������ߵ���ĵ�������û�б���Ⱥã����Ǵ�Сϲ����Ū���棬\n��λ" + RANK_D->query_respect(ob)
				+ "Ҫ�������������ߵĶ��治�������տ���\n");
			break;
		case 2:
			say( "�������ߺٺټ�Ц������λ" + RANK_D->query_respect(ob)
				+"���罫����Ĵ�����������ɣ�������ʱ����Ǯ�ġ�\n");
			break;
	}
}
int ask_me()
{
//        object ob, me;
        object me;
        me = this_player();
        if ((string)me->query("family/family_name") != "�嶾��"){
        command("say ��λ"+ RANK_D->query_respect(me)
               + "���Ǳ��̵��ӣ���ô�ܵ��������ˣ�\n");
        return 1;
         }
        command("say ���������֮�������о�������Ķ���Ĵ�(cun)������ɡ�\nÿ��ֻ�ջƽ�һ�������(qu)ʱһ�θ��壬�����ǳ��ӵķ�Ǯ���ѡ�");
        return 1;

}


