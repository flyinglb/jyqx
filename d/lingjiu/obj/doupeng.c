//doupeng.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("����", ({"dou peng", "peng"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "���Ǽ�����\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
