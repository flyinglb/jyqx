#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "���齣��" NOR, ({ "jianpu" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/huashan/linghu");
            set("long", "���������Ϊ�˼�������ɺ˵��д�µĽ��ס�\n");
          }
    setup();
}
