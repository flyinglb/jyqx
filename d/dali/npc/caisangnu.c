// caisangnu.c

inherit NPC;

void create()
{
	set_name("��ɣŮ",({ "caisang nu", "girl" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "һ������İ��Ĳ�ɣ���\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
//        set("shen", 100);
	set("shen_type", 1);
        set("per", 23);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bduanqun")->wear();
}

