// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "tiejiang", "smith" }));
	set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "�������ú���䤱��ش�����\n");

        set("combat_exp", 500);
	set("attitude", "friendly");
        set("vendor_goods",({
                   "/d/baituo/obj/dadao",
//                   "/d/baituo/obj/tiezhang",
        }));

	setup();

}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

