//yitianjian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIW"���콣"NOR, ({ "yitian jian", "yitian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 50000);
        	set("material", "iron");
        	set("long", "�������µ�һ�������С����첻����˭�����桱֮˵��\n");
        	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
                set("dynamic_quest", "/kungfu/class/mingjiao/zhangwuji");
	}
    	init_sword(500);
	setup();
}
