//cwbdao.c
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIC"��������"NOR, ({ "chuangwang baodao", "blade","baodao" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 0);
        	set("material", "iron");
        	set("long", "���Ǵ�����ʹ�ù��ĵ���������м���С�֡�\n" );
        	set("wield_msg",HIW"һ���׹⣬"+HIC+"$n"+HIW+"����$N���У�ֻ��������䣬����͸�ǣ�����������Ĵ����ս��\n"NOR);
        	set("unwield_msg", HIG"$N��"+HIC+"$n"+HIG+"������䣬�����������ؼ�ֻ��������\n"NOR);
	}
	init_blade(350);
	setup();
}
