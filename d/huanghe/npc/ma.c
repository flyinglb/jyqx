// ma.c

inherit NPC;

void create()
{
	set_name("������", ({ "ma qingxiong", "ma", "qingxiong" }));
	set("gender", "����");
	set("title", HIY"�ƺ��Ĺ�����"NOR);
	set("nickname", HIC"���Ǳ�"NOR);
	set("age", 32);
	set("str", 25);
	set("per", 15);
	set("dex", 16);
	set("long", "�������ǻƺ��Ĺ���������ǹ�������ɳͨ��������ӣ���
�ڱ޷���\n");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("whip", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("clone/weapon/changbian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

