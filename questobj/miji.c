#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIW"清官秘籍" NOR, ({ "miji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/shiye");
            set("long", "这是一本包大人写下的清官秘籍。\n");
          }
    setup();
}
