
inherit ITEM;

void create()
{
set_name( "�����޷�",({ "yunlong-bian-book", "bian book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����������ܾ���\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name": "yunlong-bian",  //name of the skill
			"exp_required": 10000 , //minimum combat experience required
			"jing_cost": 20+random(30),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59,	// the maximum level you can learn
			"min_skill":	30	// the minimum level you can learn
		]) );
	}
}
