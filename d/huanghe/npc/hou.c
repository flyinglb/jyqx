// hou.c

inherit NPC;

void create()
{
	set_name("��ͨ��", ({ "hou tonghai", "hou", "tonghai" }));
	set("gender", "����");
	set("nickname", HIC"��ͷ��"NOR);
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 11);
	set("long", "��ͨ���Ǹ��������ӣ���ռ������������������������������
���ѿ���\n");
	set("combat_exp", 100000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("club", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object(__DIR__"obj/fork")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

