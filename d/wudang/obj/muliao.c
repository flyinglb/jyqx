// muliao.c ľ��
// 2000-test-rain
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "ľ��" , ({"mu liao", "mu"}));
          set_weight(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ�ظմӷ�ľ��������ľ�ϡ�\n");
                set("value", 1);
        }
        setup();
}

