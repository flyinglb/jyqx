// gaoyao.c ��ҩ

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(RED"��"BLK"ҩ"NOR, ({ "gaoyao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����ȥ����ֵ�һ����ҩ����ߺ��ߺڡ�\n");
		set("unit", "��");
		set("value", 500);
        }
    setup();
}

void init()
{
	add_action("do_use","use");
	add_action("do_use","yong");
}


int do_use(string arg)
{
	if (!id(arg))
		return notify_fail("\n��Ҫ��ʲôҩ��\n");
	return notify_fail("\n��˺��ҩ������ֻ��һ��ֽ���и���Ŀ��Ի:\n"
        +"��ȥ�帴����ҩ��������ʲôҲû�С�\n");
}
