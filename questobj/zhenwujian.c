#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( WHT "真武剑" NOR, ({ "zhenwujian" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "口");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/wudang/zhang");
            set("long", "武当派的镇派之宝。\n");
          }
  init_sword(400);
    setup();
}
