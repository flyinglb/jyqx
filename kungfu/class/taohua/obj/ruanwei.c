// ruanwei jia

#include <armor.h>

inherit ARMOR;

void create()
{
    set_name( "��⬼�",({ "ruanwei jia","jia", }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
        	set("long", "һ����ƮƮ�ġ��������񵹴̵Ļ��ס�\n");
		set("material", "copper");
	        set("value",20000);
	        set("no_drop", "�������������뿪�㡣\n");
	        set("no_get", "�������������뿪�Ƕ���\n");
	        set("armor_prop/armor", 75);
	        set("armor_prop/dodge", -5);
	}
	setup();
}

void owner_is_killed()
{
        move(VOID_OB);
        destruct(this_object());
} 
