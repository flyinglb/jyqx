// nongfu1.c

inherit NPC;

void create()
{
	set_name("̨��ũ��",({ "nong fu", "fu" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "һλ�����̨��ũ�������������ڵ������š�\n");
        set_temp("apply/defense", 15);
	set("combat_exp", 700);
	set("shen_type", 1);
        set("per", 18);
        set("str", 24);
        set("dex", 25);
        set("con", 36);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/tongqun")->wear();
}

