// ������

inherit ITEM;

void create()
{
	set_name( "���������¾�", ({ "yunlong-jing2", "jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "\n����һ�����������¾�����Ƥ��һ�������������������֡�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"yunlong-xinfa",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20+random(20), 	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	99,	// the maximum level you can learn
			"min_skill":	50,	// the minimum level you can learn
		]) );
	}
}
