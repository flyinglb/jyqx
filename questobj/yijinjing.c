#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIY "易筋经" NOR, ({ "yijinjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/shaolin/da-mo");
            set("long", "少林寺失传的武学内功宝典。\n");
          }
    setup();
}
