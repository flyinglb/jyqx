//qingpao.c

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("��ɫ˿��", ({"si pao", "cloth", "pao"}) );
    set_weight(1000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("female_only", 1);
	set("unit", "��");
	set("long", "���Ǽ��ʵ��������ɫ�λ�˿�ۣ��ر���Ů��������\n");
	set("material", "cloth");
        set("value",70);
	set("armor_prop/armor", 4);
    }
    setup();
}
