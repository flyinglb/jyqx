// shu-sheng.c

inherit NPC;

void create()
{
	set_name("����", ({ "shu sheng", "sheng" }) );
	set("gender", "����" );
	set("age", 22);
	set("int", 28);
	set("long",
		"���Ǹ�����ʫ�飬ȴ���޲���֮��������������\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

