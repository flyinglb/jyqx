// laozi1.c
// Marz

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾�����һ�¡�", ({ "daode-jing1", "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN
			"\n\t\t\t��һ��\n\n"
			"\n\t���ɵ����ǳ��������������ǳ�����\n"
			"\t�������֮ʼ����������֮ĸ��\n"
			"\t�ʳ��ޣ����Թ�������У����Թ����衣\n"
			"\t�����ߣ�ͬ����������ͬν֮������֮����������֮�š�\n\n"
			NOR
		);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	 0,	// minimum combat experience required
			"jing_cost":    10, 	// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	29,	// the maximum level you can learn
		]) );
	}
}
