// tshangfan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("̨���̷�", ({ "shang fan", "shang", "fan" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "һλ̨������̷������ڷ���һ��¨�մ������Ļ�����������㡣\n");
	set("combat_exp", 3000);
        set("per", 17);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/ttoujin")->wear();
	carry_object(__DIR__"obj/tduanqun")->wear();
	add_money("coin", 100);
}

