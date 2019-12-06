// Npc: /d/shaolin/npc/xiao-tong.c
// Date: zqb 97/06/17

inherit NPC;


void create()
{
	set_name("Сͯ", ({
		"xiao tong",
		"xiao",
		"tong",
	}));
	set("long",
		"����һλδͨ���ʵ����꣬���Ϲ����������Ц��\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	

	set("age", 10);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("strike", 10);
	set_skill("parry", 10);


	setup();

}




