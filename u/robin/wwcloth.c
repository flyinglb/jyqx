// cloth: wwcloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( "布衣" , ({ "Cloth", "yi"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件神奇服装\n");
		set("material", "silk");
		set("armor_prop/armor", 2000);
//		set("value", 50);
	}
	setup();
}
void init()
{
        add_action("do_magic", "magic");
}
int do_magic(string arg)
{
        object me;
        if (!arg ||arg !="sec") return 1;
        me = this_player();
        message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n",me);
        me->move("/u/robin/room/wuchang2");
        return 1;
}
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
   return 1;
}
