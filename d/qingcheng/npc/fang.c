// fang.c 

inherit NPC;

void create()
{
	set_name("������", ({ "fang renzhi", "fang", "renzhi" }));
	set("gender", "����");
	set("age", 20);
	set("long", "�����ǡ�����ɡ�����һ�����ӣ����Ǽ�Ϊʦ��ϲ����\n");

	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("sword", 50);
	set_skill("pixie-sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "pixie-sword");
	map_skill("sword", "pixie-sword");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
