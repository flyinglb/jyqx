#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name( RED "ĞşÌú´¸" NOR, ({ "xuetie chui" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¸ù");
            set("material", "paper");
            set("dynamic_quest", "/d/village/npc/smith");
            set("long", "·ëÌú½³µÄĞşÌú´¸¡£\n");
          }
    init_hammer(20);
    setup();
}
