// hongniang.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "hong niang", "hong" }));
	set("long", 
		"����һ�����úܺÿ���С���\n"
		"��Ϊ�����ڴ˴�������¶��һ˿���ݡ�\n");
	set("gender", "Ů��");
	set("age", 16);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	setup();
}
