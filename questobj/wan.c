#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "����������" NOR, ({ "zaizaowan" }) );
    set_weight(60);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/ping");
            set("long", "һ�ſ�������������ҩ�衣\n");
          }
    setup();
}
