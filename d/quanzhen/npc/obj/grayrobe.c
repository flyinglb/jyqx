// greyrobe.c ��ɫ����

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"��ɫ����"NOR, ({"pao", "cloth", "dao pao"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ͨͨ�ĻҲ����ۡ�\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
