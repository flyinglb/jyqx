#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name( HIM "Ä§µ¶" NOR, ({ "modao" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿Ú");
            set("material", "paper");
            set("dynamic_quest", "/d/xiaoyao/npc/suxingh");
            set("long", "ËÕÐÇºÓµÄÄ§µ¶¡£\n");
          }
    init_blade(100);
    setup();
}
