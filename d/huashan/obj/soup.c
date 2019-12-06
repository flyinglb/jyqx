// soup.c
// By Marz 03/29/96

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(MAG"����"NOR, ({"soup"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������˱ǵ�����Ұ����������\n");
		set("unit", "��");
		set("value", 80);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "�ʹ���",
        "remaining": 6,
        "drunk_supply": 20,
    ]));
}
