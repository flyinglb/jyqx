// chang2.c ����־

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����־", ({ "chang bozhi", "chang","bozhi" }));
	set("title", HIR "�컨��"HIG"������" NOR);
	set("nickname", HIB "���޳�" NOR);
	set("long", 
"������ָ����ݣ���ɫ���ƣ��۾�������üëбб�ĵ�����������
�����ǿɲ�����������ɻ��µ��˵�ͽ�ܡ���ɳ�ƵĹ��򣬽�������
���ܵС��ڰ��޳����ֵ��Ǵ�����������������һ��ٸ���ƶ������
�ĺ���������˵�������������š�\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "aggressive");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("yunlong-shengong", 120);
	set_skill("yunlong-shenfa", 120);
	set_skill("yunlong-shou", 120);
	set_skill("yunlong-zhua", 120);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);
	create_family("�����",21, "����");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
     ::init();
     remove_call_out("greeting");
      call_out("greeting", 1);
}

void greeting()
{
      object room;
     room=environment(this_player());
   if (file_name(room)=="/d/hangzhou/liuhe8") set("attitude", "aggressive");
   else set("attitude","peaceful");
}
