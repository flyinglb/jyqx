// feather.c
// modified by wind

#include <armor.h>
#include <ansi.h>
// #include mudlib.h

inherit CLOTH;

void create()
{
      set_name(HIG"��ȸ����"NOR, ({ "feather" }) ); 
//         set("no_drop", "1");
        set_weight(600);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����ȸ�������ÿ�ȸ��ë֯�ɵġ�\n");
                set("unit", "��");
	        set("value", 5000);
                set("material", "feature");
//                set("armor_prop/personality", 10);
                set("armor_prop/armor", 10);
//                set("armor_prop/armor_vs_force", 10);
//                set("armor_prop/attack", -2); 
        }
        setup();
}

