// jiading.c �Ҷ�

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "jia" }));
	set("gender", "����");
	set("age", 35);
	set("long", "��ɽ����ү���ϵļҶ���ռ�����ˣ����аԵ���\n");
	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", -1);
	setup();

	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}
