#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED "胡家刀谱" NOR, ({ "daopu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/d/guanwai/npc/hufei");
            set("long", " 被阎基偷走的绝世刀谱。\n");
          }
    setup();
}
