// ttoujin.c
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("̨��ͷ��", ({ "tou jin" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ��̨��ͷ�����Բ���ͷ����\n");
		set("value", 1500);
		set("armor_prop/dodge", -5);
	}
	setup();
}
