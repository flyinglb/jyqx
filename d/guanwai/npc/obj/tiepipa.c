// tiepipa.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIC"������"NOR, ({ "tiepipa" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ã�������൱���ɼ�ʵ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ӱ��Ͻ���һ��$n��Ȼ��������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(45);
        setup();
}
