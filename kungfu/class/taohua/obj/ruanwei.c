// ruanwei jia

#include <armor.h>

inherit ARMOR;

void create()
{
    set_name( "软猬甲",({ "ruanwei jia","jia", }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "件");
        	set("long", "一件轻飘飘的、生满尖锐倒刺的护甲。\n");
		set("material", "copper");
	        set("value",20000);
	        set("no_drop", "这样东西不能离开你。\n");
	        set("no_get", "这样东西不能离开那儿。\n");
	        set("armor_prop/armor", 75);
	        set("armor_prop/dodge", -5);
	}
	setup();
}

void owner_is_killed()
{
        move(VOID_OB);
        destruct(this_object());
} 
