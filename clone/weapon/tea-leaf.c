// tea_leaf.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
        set_name("��Ҷ", ({ "tea_leaf", "tea" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�Ųɵ��²裬����һ�ɵ�����������\n");
                set("unit", "��");
                set("value", 0);
                set("base_unit", "Ƭ");
                set("base_weight", 1);
                set("base_value", 0);
		set("damage", 1);	//Here the damage=int_throwing, added by King
        }
        set_amount(50);
        init_throwing(1);
        setup();
}
