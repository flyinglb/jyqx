//baipao.c
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({"chang pao", "cloth", "pao"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "��");
		set("long", "���Ǽ������ϼѵİ�ɫ���ۡ�\n");
	set("material", "cloth");
	set("armor_prop/armor", 7);
        set("value",100);
    }
    setup();
}
