// daihu.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�����", ({ "dai daifu", "dai" }));
        set("str", 60);
        set("gender", "����");
        set("age", 18);
        set("long", "���������ǵ���ҽ,�ڳ��о�������,����𾴡�\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/clone/misc/jinchuang",
                "/clone/misc/yangjing",
                "/clone/misc/wuchangdan",
                "/clone/misc/zhujingchan",
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

