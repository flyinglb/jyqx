// necklace.c �Ǵ�
 
#include <armor.h>
 
inherit SURCOAT;
 
void create()
{
	set_name("�Ǵ�", ({ "surcoat", "du dai", "dai" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ��Ƥ�ʵĶǴ������Ա���������\n");
		set("value", 800);
		set("armor_prop/dodge", -3);
	}
	setup();
}