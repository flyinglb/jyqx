#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "��Ů��" NOR, ({ "hua" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "��");
            set("dynamic_quest", "/d/gumu/npc/longnv");
            set("long", "С��Ů����Ů����\n");
          }
    setup();
}
