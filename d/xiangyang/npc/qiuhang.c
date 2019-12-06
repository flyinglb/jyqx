// qiuhang.c �� 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��", ({ "qiu hang", "qiu" }));
	set("title", "�����ϰ�");
	set("nickname", "�ϻ�ͷ");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 55);
	set("str", 100);
	set("long", "һ���ϼ��̣���Ҫ�����ˣ�\n");
	set("no_get_from", 1);
        set("no_beg_from", 1);
        set("no_steal_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
