#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIY "��"NOR, ({ "gold axe", "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
                set("long", "����һ���ý������ɴ��ӣ������ޱȣ���ʮ�ֳ��ء�\n");
		set("value", 500);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_give", 1);
//                set("no_get", 1);
                set("wield_msg", HIY "���һ����ֻ��$N�ֶ���һ��$n��\n"NOR);
                set("unwield_msg", "$N�������е�$n��\n");
	}
        init_axe(500, TWO_HANDED);
	setup();
}

