// funu.c

inherit NPC;

void create()
{
	set_name("�帾",({ "cun fu", "woman" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long", "һ������İ��Ĵ帾��\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 3000);
	set("shen_type", 1);
        set("per", 20);
        set("str", 24);
        set("dex", 25);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/tduanqun")->wear();
}

