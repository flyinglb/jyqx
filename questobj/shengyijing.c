#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "���⾭" NOR, ({ "shengyijing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/d/city/npc/tang");
            set("long", "����һ����骼����������⾭��˵��ֵ���ǡ�\n");
          }
    setup();
}
