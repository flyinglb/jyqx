#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( YEL "九阴真经" NOR, ({ "jiuyinzhenjing" }) );
    set_weight(2);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/btshan/ouyangfeng");
            set("long", "这是郭靖错写给欧阳峰的九阴真经。\n");
          }
    setup();
}
