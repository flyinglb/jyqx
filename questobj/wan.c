#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "生生再造丸" NOR, ({ "zaizaowan" }) );
    set_weight(60);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "颗");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/ping");
            set("long", "一颗可以起死回生的药丸。\n");
          }
    setup();
}
