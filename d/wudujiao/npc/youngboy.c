// youngboy.c  ��������
inherit NPC;

void create()
{
	set_name("��������", ({ "young boy", "boy" }));
	set("gender", "����");
	set("age", 20);
       set("per",30);
       set("max_qi",400);
	set("long", "һ����������ε�Ӣ�����ꡣ\n");
	set("combat_exp", 8000);
	set("shen_type", 1);
       set_skill("unarmed", 30);
       set_skill("dodge", 30);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
	
