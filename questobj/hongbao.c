#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "红包" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/tang");
            set("long", "当然是......\n");
          }
    setup();
}
