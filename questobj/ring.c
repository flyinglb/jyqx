#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "��"HIC"��"HIY"ָ"HIW"��" NOR, ({ "ring" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "��");
            set("dynamic_quest", "/kungfu/class/xinxiu/ding");
            set("long", "��ң�ɵİ��������\n");
          }
    setup();
}
