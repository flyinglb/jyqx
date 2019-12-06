//NPC snaker.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void greeting(object ob);
void create()
{
	set_name("������", ({ "snaker" }));
	set("long", "����һ���������������ˡ�\n");
	set("title", "��������");
	set("nickname", HIY "�߼���" NOR);
	set("gender", "����");
	set("age", 33);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);
	;

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 20);
	set("combat_exp", 30000);
   set("snake_mount" ,3);
	set("score", 10000);

	set("chat_chance",5);
	set("chat_msg", ({
		"������ߺ�ȵ�:ͣһͣ����һ�������Ϻõ��ߵ��۳����ˣ�\n",
		"�����˰����󻮳�һ�����ӣ��ַ����ߵ��ۣ��ף���Ѫ����ֹͣ�ˡ�\n",
		"�����˰��������������ȥ���������ʵ�����������û����\n",
	}) );

	set("inquiry", ([
		"����ɽ" : "��������ߵ��۾����ð���ɽ���߾��������ġ�\n",
		"�ߵ���" : "�ҵ��ߵ������θ������ˣ���Ч������\n",
	]));
	 set("vendor_goods", ({
	 "/d/baituo/obj/fen",
	 }));

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
}

void init()
{
	object ob;

	::init();
        add_action("do_list","list");
        add_action("do_buy","buy"); 
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
       
}
/*
void greeting(object ob)
{       object obn;
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "����ɽ��")
	{
	  if(!present("shenshe",ob)&&random(2)==1)
	     {
	      tell_object(ob,"��λ"+RANK_D->query_respect(ob)+"���������С���·���ߡ���\n"+
	       "������ȥ�ã����õ��ģ��������İ�������\n");
	      obn=new("/d/baituo/obj/shenshe");
	      obn->move(ob);
	      return;
	     }
	}
      say("���������ڵ�˵����λ"+RANK_D->query_respect(ob)+"�����ҵ��ߵ��۰ɣ��������⡣\n");
      return;
}
*/

int accept_fight(object ob)
{
	object obn;
	if(!objectp(present("mang she",environment(ob))))
	{
	add("snake_mount", -1);
	if(!query("snake_mount")) { message_vision("������ŭ�� �㻹��ƭ���ӵ������ޣ��� \n",ob);  return 1; }
	message_vision("�����˴��һ����С�Ӿ��Ҹ����ӹ���ȥ�������ߵ�������\n", ob);
	obn=new("/d/baituo/npc/mangshe");
	obn->move(environment(ob));
	obn->kill_ob(ob);
	return 0;
	}
	message_vision("�����˴�ŭ��������С�ӳ������ӵ�������\n", ob);
	return 1;
}

