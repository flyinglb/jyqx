// nongfu2.c

inherit NPC;

void create()
{
	set_name("ũ��",({ "nong fu", "fu" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "һλ��ǿ��׳�İ�����ũ��\n");
        set_temp("apply/defense", 15);
	set("combat_exp", 2700);
	set("shen_type", 1);
        set("per", 18);
        set("str", 24);
        set("dex", 25);
        set("con", 36);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/maotan")->wear();
}

