// toukui.c ͷ��
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("ͷ��", ({ "helmet", "toukui" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ�����ʵĶǴ������Ա���ͷ����\n");
		set("value", 1500);
		set("armor_prop/dodge", -5);
	}
	setup();
}