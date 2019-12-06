// cloth: wwcloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( "����" , ({ "Cloth", "yi"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������װ\n");
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
        message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n",me);
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
