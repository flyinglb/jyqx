// cungu.c

inherit NPC;

void create()
{
	set_name("���", ({ "cun gu","gu","cun" }) );
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "һ�������������ũ��������һֻ���Ų�С���ӡ�\n");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 15);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/baituo/obj/caomei");
        carry_object("/d/baituo/obj/turou");
}

