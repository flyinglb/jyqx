inherit ITEM;

void create()
{
	set_name( "��ɽ�����Ʒ�ͼ�ϲ�", ({ "zhangfa tu1", "tu1" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������Ʒ��ϲᣬ���滭��һЩ�׷����ӵ���ʽ���������š�\n");
		set("value", 500);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"liuyang-zhang",	
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":    20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	49,	// the maximum level you can learn
			"min_skill":	10,	// the maximum level you can learn
		]) );
	}
}
