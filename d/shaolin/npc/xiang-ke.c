// xiang-ke.c �����

inherit NPC;

void create()
{
	int value;

	value = random(10);

	set_name("�����", ({ "jingxiang ke", "ke", "guest" }));
	set("gender", "����");
	set("age", 14 + value * 3 );

	set("combat_exp", 500 + 5 * value);
	set("shen_type", 0);
	setup();
	add_money("silver", 1 + value);
}
