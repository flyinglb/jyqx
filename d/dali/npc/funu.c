// funu.c

inherit NPC;

void create()
{
	set_name("̨�ĸ�Ů",({ "fu nu", "woman" }) );
        set("gender", "Ů��" );
        set("age", 37);
        set("long", "һλ�����̨�ĸ�Ů����������Ļ��Խ��´���ɫͲȹ�����ڱ�֯������\n");
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
        carry_object(__DIR__"obj/tongqun")->wear();
}

