inherit ITEM;

void create()
{
	set_name( "��ɽ�����Ʒ�ͼ�²�", ({ "zhangfa tu2", "tu2" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������Ʒ��²ᣬ���滭��һЩ�׷����ӵ���ʽ���������š�\n");
		set("value", 500);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"liuyang-zhang",	
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost":    40, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	149,	// the maximum level you can learn
			"min_skill":	100,	// the minimum level you can learn
		]) );
	}
}
