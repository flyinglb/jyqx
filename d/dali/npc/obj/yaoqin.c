// tiepipa.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name("����", ({ "yao qin" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѹ�Ů�õ����٣��������൱����ϸ�塣\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N�ӱ��Ͻ���һ��$n��Ȼ��������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(5);
        setup();
}
