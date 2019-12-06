#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( YEL "五毒密传" NOR, ({ "wudumizhuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/d/quanzhou/npc/limochou");
            set("long", "李莫愁自己撰写的刻毒密传。\n");
          }
    setup();
}
