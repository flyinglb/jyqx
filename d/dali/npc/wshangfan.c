// wshangfan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����̷�", ({ "shang fan", "shang", "fan" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "һλ��������̷�������һ��ƤëҰζ�ڷ�����\n");
	set("combat_exp", 5000);
        set("str", 27);
        set("str", 22);
        set("dex", 11);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/wdahui")->wear();
	add_money("coin", 100);
}

