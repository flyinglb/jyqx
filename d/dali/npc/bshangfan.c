// bshangfan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("̨���̷�", ({ "shang fan", "shang", "fan" }) );
	set("gender", "Ů��" );
	set("age", 32);
	set("long", "һ�����ĸ�Ů�����Ÿ���¨����Щ˿֯��Ʒ���ֹ���Ʒ��\n");
	set("combat_exp", 2500);
        set("per", 17);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/bduanqun")->wear();
	add_money("coin", 100);
}

