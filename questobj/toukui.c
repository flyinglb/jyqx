#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
	set_name(YEL"�ƽ�ͷ��"NOR, ({ "toukui" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("material", "gold");
            set("dynamic_quest", "/d/guiyun/npc/wanyankang");
	}
}
