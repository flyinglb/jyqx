// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(HIC"ѩ����"NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������˱ǵ�ѩ������\n");
                set("unit", "��");
                set("value", 80);
        set("max_liquid", 4);
    }

    set("liquid", ([
        "type": "water",
        "name": "ѩ����",
        "remaining": 6,
        "drunk_supply": 20,
    ]));
}

