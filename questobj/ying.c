#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED "��ɳ��Ӱ" NOR, ({ "sheying" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ͳ");
            set("material", "none");
            set("dynamic_quest", "/quest/weixiaobao");
          }
    setup();
}
