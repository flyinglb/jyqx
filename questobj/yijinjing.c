#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIY "�׽" NOR, ({ "yijinjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("dynamic_quest", "/kungfu/class/shaolin/da-mo");
            set("long", "������ʧ������ѧ�ڹ����䡣\n");
          }
    setup();
}
