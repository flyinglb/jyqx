// yafu.c

inherit NPC;

void create()
{
	set_name("�Ƹ�",({ "yafu" }) );
        set("gender", "Ů��" );
        set("age", 37);
        set("long", "���Ǹ����겻���ڵ��Ƹ�\n");
        set("combat_exp", 50000);
	set("shen_type", 0);
	set("str", 21);
	set("per", 20);
	set("dex", 21);
	set("con", 21);
	set("int", 21);
        set("attitude", "friendly");
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

