//jinmu.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIM"���׽�ĸ"NOR, ({ "jin mu","jin","mu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�麣�׽�ĸ�����������ƵĹ⣬�����������ģ�\n"
		    "�ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0);
                set("material", "iron");
              }
}

void owner_is_killed()
{
        destruct(this_object());
}
