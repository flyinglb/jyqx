//changpao.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("����", ({"chang pao", "cloth","pao"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "���Ǽ������ϼѳ��ۣ�����[����]���ַ��Ƶġ�\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
