#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( YEL "�����澭" NOR, ({ "jiuyinzhenjing" }) );
    set_weight(2);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/btshan/ouyangfeng");
            set("long", "���ǹ�����д��ŷ����ľ����澭��\n");
          }
    setup();
}
