#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "�������" , ({ "jindai" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ý�˿֯�ɵ���������\n");
                set("value", 1500);
                set("material", "silk");
                set("armor_prop/armor", 1);
		set("female_only", 1);
        set("wear_msg", "$N��$n�ó�����ͷ���ϡ�\n");
        }
        setup();
}
