// tongren.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIY"����ͭ��"NOR, ({ "tongren" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ���صĶ���ͭ�ˣ�������൱�ִ��ʵ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һֻ$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(50);
        setup();
}
