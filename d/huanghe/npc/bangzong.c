// bangzong.c

inherit NPC;

void create()
{
	set_name("��", ({ "da han", "han" }));
	set("gender", "����");
	set("title", HIY"�ƺӰ����"NOR);
	set("age", 22);
	set("str", 25);
	set("per", 15);
	set("dex", 16);
	set("long", "һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����\n");
	set("combat_exp", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("axe", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("neili", 100); 
	set("max_neili", 100);
	set("jiali", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

