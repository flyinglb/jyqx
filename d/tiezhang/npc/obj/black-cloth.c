// cloth.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(BLK"��ɫʥ��"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","����һ�����ź�ɫ����ĺ�ɫʥ�¡�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
