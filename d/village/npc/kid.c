// kid.c

inherit NPC;

void create()
{
	set_name("С��",({ "kid" }) );
        set("gender", "����" );
        set("age", 7);
        set("long", "���Ǹ�ũ��С����\n");
        set("combat_exp", 50);
//        set("shen", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

