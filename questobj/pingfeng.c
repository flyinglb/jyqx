#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "大理石屏风" NOR, ({ "pingfeng" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "paper");
            set("dynamic_quest", "/quest/weixiaobao");
            set("long", "韦小宝在吴三桂的五华宫的书房中所见，是吴三桂的
三宝之一。\n");
          }
    setup();
}
