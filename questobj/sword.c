#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( HIM "古剑" HIY" 天清" NOR, ({ "tianqing" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "口");
            set("material", "paper");
            set("dynamic_quest", "/d/npc/duanyu");
            set("long", "不用说，一看就知道是一柄超凡脱俗的宝剑。\n");
          }
    init_sword(120);
    setup();
}
