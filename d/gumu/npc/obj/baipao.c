//baipao.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW "����" NOR, ({"bai pao", "pao"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǽ���ɴ�Ƴɵİ�ɫ���ۡ�\n");
                set("material", "silk");
                set("armor_prop/armor", 8);
                set("value",100);
        }
        setup();
}
