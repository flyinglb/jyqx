// xiucai.c

inherit NPC;

void create()
{
	set_name("������", ({ "xiu cai" }) );
	set("gender", "����" );
	set("age", 26);
	set("int", 28);
	set("long",
		"���Ǹ�����ʫ�飬ȴ���޲���֮���������š�\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

