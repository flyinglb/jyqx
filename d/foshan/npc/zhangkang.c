// zhangkang.c

inherit NPC;

void create()
{
	set_name("�ſ�", ({ "zhang kang", "zhang" }));
	set("gender", "����");
	set("age", 25);
	set("per", 20);
	set("long", "���Ǹ���ʵ�ͽ��ĺ��ӣ����ų��ƵĴ��ˡ�\n");
	set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();

	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}

