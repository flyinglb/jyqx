// jinsijia.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY"��˿��"NOR, ({ "jinsi jia", "jia"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
/*
                set("no_get", "1");
                set("no_put", "1");
                set("no_beg", "1");
                set("no_drop", "1");
                set("no_steal", "1");
*/
                set("value", 30000);
                set("material", "leather");
                set("armor_prop/armor", 100);
        }
        setup();
}

int query_autoload()
{
   return 1;
}
void owner_is_killed()
{
        write(HIY"ֻ����ǰ���һ��...������.....\n"NOR);
        destruct(this_object());
} 
