// zhuge.c
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
        set_name("�����", ({ "zhuge" }) );
        set("gender", "����" );
        set("age", 35);
	 set("per", 30);
        set("long", "һλ�����ڽ��ɷ���ǵ���ʿ��\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
//      set("env/wimpy", 50);
	 set_skill("dodge", 80);
	 set_skill("unarmed",80);
	 set_skill("parry", 80);
	 set_skill("literate", 150);

  	set("chat_chance",10);
  	set("chat_msg",({
	WHT"�����̾����������֪���ģ����������о���γ��֮�ţ��κ�����֪������......��\n"NOR,

//        (:random_move:)
    	}));
        setup();
        add_money("silver", 20);
set("inquiry", ([
"name": "������������֮�ڶ�ʮ�������������Ҳ��\n",
"here": "���������ڣ������������֮��Ҳ��\n",
"�����": "��������ֱ�����������䣿\n",
"��������": "������֮����Ҳ���������ϻ�ƽ�����Ͻ���\n
�ʶ�������ȥ�Ͻ����������������һ��֮��",
"����": (: ask_me :),
"�һ���": (: ask_me :),
"����о�ɢ": (: ask_me :),
]) );
        carry_object("/d/city/obj/cloth")->wear();
}
int ask_me()
{
 //       mapping fam; 
        object ob;
//        if ((this_player()->query("shen")) < -1000)
//              return notify_fail("���ô...,���²�֪Ҳ��\n");
  
       command("say �置�һ��������ն��쳣��������������������֮������о�ɢ����������\n");
 command("say ���ҩҪ����Я������ĩ�������мǣ��мǣ�");
        ob = new(__DIR__"obj/xingjunsan");
        ob->move(this_player());
 //       return "��ȥ�ɡ�";
         return 1;
}
