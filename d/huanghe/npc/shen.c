// shen.c

inherit NPC;

void create()
{
	set_name("�����", ({ "shen qinggang", "shen", "qinggang" }));
	set("gender", "����");
	set("title", HIY"�ƺ��Ĺ��ϴ�"NOR);
	set("nickname", HIC"�ϻ굶"NOR);
	set("age", 32);
	set("str", 25);
	set("dex", 16);
	set("per", 16);
	set("long", "������ǻƺ��Ĺ���ϴ��ǹ�������ɳͨ��Ĵ���ӣ���
ʹ������\n");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("blade", 30);
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
	carry_object("clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

