// duantiande.c

inherit NPC;

void create()
{
	set_name("�����", ({ "duan tiande", "duan" }));
	set("gender", "����");
	set("title", "���α���ָ��ʹ");
	set("age", 45);
	set("per", 15);
	set("long", "���Ǵ����ٰ�����ָ��ʹ��\n");
	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
	set("shen_type", -1);
	setup();

	add_money("gold",3);
	carry_object("/d/city/npc/obj/junfu")->wear();
}

