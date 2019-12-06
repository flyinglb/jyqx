#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "七"HIC"宝"HIY"指"HIW"轮" NOR, ({ "ring" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "颗");
            set("material", "玉");
            set("dynamic_quest", "/kungfu/class/xinxiu/ding");
            set("long", "逍遥派的帮主的信物。\n");
          }
    setup();
}
