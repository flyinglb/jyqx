// zhang.c

inherit NPC;

void create()
{
	set_name("�ų���", ({ "zhang chaotang", "zhang" }) );
	set("gender", "����" );
	set("age", 22);
	set("int", 28);
	set("per", 23);
	set("long", 
"���Ǹ�����ʫ���������������һֱ���������Ļ��������Ͽ���\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

