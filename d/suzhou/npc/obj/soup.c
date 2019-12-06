// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(HIG"��Ҷ������"NOR, ({"soup"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������˱ǵĺ�Ҷ��������\n");
		set("unit", "��");
		set("value", 150);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "��Ҷ������",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}
