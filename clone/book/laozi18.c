// laozi18.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾�����ʮ���¡�", ({ "daode-jing18", "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t��ʮ����\n\n"
			"\t����ϣ������壻�ǻ۳����д�α�����ײ��ͣ���Т�ȣ����һ�\n"
			"�ң����ҳ���\n"
			"\n"NOR
		);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	 0,	// minimum combat experience required
			"jing_cost":	10, 	// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	29,	// the maximum level you can learn
		]) );
	}
}
