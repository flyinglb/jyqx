// jinshe-zhui.c
 
#include <weapon.h>
#include <ansi.h>
 
inherit THROWING;
 
void create()
{
	set_name(YEL"����׶"NOR, ({ "jinshe zhui", "zhui" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", 
"����׶�ǻƽ��������������⡣��Լ����˷֣���ɰ����������
�Σ������˷ֳ�˫�棬ÿһ�涼��һ�����̡�\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "ö");
		set("base_weight", 10);
		set("base_value", 0);
		set("damage", 50);
	}
	set_amount(15);
	init_throwing(50);
	setup();
}
