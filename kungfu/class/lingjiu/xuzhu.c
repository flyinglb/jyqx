// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "����һ����ʮ�������������, Ũü����,\n"+
	    "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
	    "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
	    "��������ɽͯ�ѵľ�������.\n");
	set("title", "���չ�������");
	set("gender", "����");
	set("age", 26);
	set("nickname", HIR "����" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);

	set("combat_exp", 1500000);
	set("score", 20000);
	set_skill("force", 150);
	set_skill("unarmed", 180);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",180);
	set_skill("strike", 180);

	set_skill("zhemei-shou",150);
	set_skill("liuyang-zhang",150);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 150);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("���չ�",2, "����");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	   }  
   if ((string)ob->query("gender")=="Ů��")
   {
		message_vision("����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
       return;}
   else
      {
		message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
       return;}
}
