// linpingzhi.c ��ƽ֮

inherit NPC;

void create()
{
	set_name("��ƽ֮", ({ "lin pingzhi", "lin", "pingzhi" }));
	set("gender", "����");
	set("age", 20);
	set("long", "�����ǡ������ھ֡����ٵ��ң�����ƽ֮��\n");

	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("sword", 40);
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 10);

	setup();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}
	
