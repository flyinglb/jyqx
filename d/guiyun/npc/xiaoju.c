// xiaoju.c

inherit NPC;

void create()
{
	set_name("С��", ({ "xiao ju", "ju" }));
	set("long", "һ��ģ�����ɵ�СѾ��������������ɫ������ϸ��ʱ�������һ��С�롣\n");
	set("gender", "Ů��");
	set("age", 15);
	set("combat_exp", 1000);
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();

	add_money("silver",1);
	carry_object(__DIR__"obj/red_cloth")->wear();
}

