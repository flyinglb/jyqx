// heiyiren.c ������̽�ͽ
inherit NPC;
void create()
{
	set_name("������", ({ "heiyi ren", "ren" }));
	set("gender", "����");
	set("age", 25);
	set("title", "������̷����õ���");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);	
        set("apply/attack", 50);
	set("apply/defense", 50);
	set("apply/damage", 25);
	set("combat_exp", 30000);
	set("shen_type", -1);
	setup();
}	
