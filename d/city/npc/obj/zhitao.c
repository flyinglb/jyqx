// zhitao.c ָ��

#include <armor.h>

inherit FINGER;

void create()
{
	set_name( "ָ��", ({ "finger", "zhitao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�������������������ָ�ף�ǰ�˷������У��ȿɰ����������ˣ��ֿɱ���ָ�ؽڡ�\n");
		set("value", 6000);
		set("material", "steel");
		set("armor_prop/armor", 5);
	}
	setup();
}
