// yuyan.c 

inherit NPC;

void create()
{
	set_name("������", ({ "yu renyan", "yu", "renyan" }));
	set("gender", "����");
	set("age", 20);
	set("long", "�����ǡ�����ɡ���������׺��Ķ������ӡ�������ʵ�ںܲ�������\n");

	set("combat_exp", 40000);
	set("shen_type", -1);

	set_skill("sword", 40);
	set_skill("pixie-sword", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	map_skill("parry", "pixie-sword");
	map_skill("sword", "pixie-sword");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
