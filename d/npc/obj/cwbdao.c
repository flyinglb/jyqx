//cwbdao.c
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("��������", ({ "chuangwang baodao", "chuangwang","baodao" }) );
    set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 0);
        	set("material", "iron");
        	set("long", "���Ǵ�����ʹ�ù��ĵ���������м���С�֡�\n" );
        	set("wield_msg","һ���׹⣬$n����$N���У�ֻ��������䣬����͸�ǣ�����������Ĵ����ս��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
	}
    	init_blade(1000);
	setup();
}
