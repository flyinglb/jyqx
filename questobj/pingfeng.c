#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "����ʯ����" NOR, ({ "pingfeng" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/quest/weixiaobao");
            set("long", "ΤС������������廪�����鷿�����������������
����֮һ��\n");
          }
    setup();
}
