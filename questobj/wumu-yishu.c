#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIC"��������"NOR, ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			GRN
			"\n���������������ǰ���µġ��ƽ�Ҫ������\n"
			"ֻ����һҳ��д��ʮ�˸����֣�\n"
                        "������ѡ����ѵϰ��\n"
                        "�����ͷ��������\n"
                        "���ϼ�  ��ͬ�ʿࡱ\n"
               NOR
		);
		set("value", 10000000);
		set("material", "paper");
            set("dynamic_quest", "/d/npc/guojing");
	}
}
