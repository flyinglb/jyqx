#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name( RED "������" NOR, ({ "xuetie chui" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/village/npc/smith");
            set("long", "����������������\n");
          }
    init_hammer(20);
    setup();
}
