// tielianzi.c
 
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
 
void create()
{
	set_name(BLK"������"NOR, ({ "tie lianzi", "lianzi", "zi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������Ƶ�����״������\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
                set("material", "iron");
		set("damage", 5);	//Here the damage=int_throwing, added by King
		set("wield_msg", HIC"$NѸ�ٵشӰ��������ͳ�һЩ�����ӣ��������оʹ�������\n"NOR);
		set("unwield_msg",HIC"$N������ʣ�µ������Ӿ����Żذ������С�\n"NOR);
	}
	set_amount(30);
	init_throwing(5);
	setup();
}
