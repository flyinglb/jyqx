#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIW "��Ѫ��" NOR, ({ "chai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "��");
            set("dynamic_quest", "/d/city/yingying");
            set("long", "��ң�ɵİ��������\n");
          }
    setup();
}
