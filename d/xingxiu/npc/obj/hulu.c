// hulu.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>;

void create()
{
        set_name(HIG"���«"NOR, ({ "qing hulu", "hulu" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɫ�ĺ�«��\n"
);
                set("unit", "��");
                set("value", 80);
                set("max_liquid", 60);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "water",
                "name": "��Ȫˮ",
                "remaining": 60,
        ]) );
}
