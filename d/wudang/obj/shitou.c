// shitou.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
    set_name(HIW"��ʯͷ"NOR, ({ "shi tou"}));
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "����һƽƽ�����Ĵ�ʯͷ��\n");
        set("value", 0);
        set("material", "stone");
		set("wield_msg", "$N����һ��$n׼��ս����\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

    init_hammer(1);
	setup();
}
