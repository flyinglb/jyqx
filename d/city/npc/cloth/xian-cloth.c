// xian-cloth.c example cloth

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( BLK "��ɫ�����" NOR, ({ "cloth" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/personality", 1);
                set("armor_prop/armor", 2);
                set("wear_msg","$N����һ��$n��\n");
                set("remove_msg","$��$n����������\n");
        }
}

