
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "��˿����" NOR, ({ "bao jia", "jia" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��������/�����˵ģ�Ҳ���ܸ����ˡ�");
                set("value", 50000);
                set("material", "gold");
                set("armor_prop/armor", 500);
        }
        setup();
}

