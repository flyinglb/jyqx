// muyangren.c

inherit NPC;

void create()
{
	set_name("������",({ "muyang ren", "ren" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "��һ�������������ӡ�\n");
        set_temp("apply/defense", 15);
	set("combat_exp", 170);
	set("shen_type", 1);
        set("per", 18);
        set("str", 24);
        set("dex", 25);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/wchangqun")->wear();
        carry_object("/d/xingxiu/obj/bian")->wear();
}

