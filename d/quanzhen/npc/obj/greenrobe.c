// greenrobe.c ��ɫ����

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG"��ɫ����"NOR, ({"pao", "cloth", "dao pao"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("female_only", 1);
                set("unit", "��");
                set("long", "���Ǽ��ʵ��������ɫ���ۡ�\n");
                set("material", "silk");
                set("armor_prop/armor", 3);
        }
        setup();
}
