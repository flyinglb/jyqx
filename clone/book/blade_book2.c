inherit ITEM;

void create()
{
	set_name("刀法进阶", ({ "blade_book2", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"封面上写着“刀法进阶”\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"blade",	// name of the skill
			"exp_required":	1000,		// minimum combat experience required
							// to learn this skill.
			"jing_cost":	20,		// jing cost every time study this
			"difficulty":	20,		// the base int to learn this skill
							// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	120,		// the maximum level you can learn
							// from this object.
                        "min_skill":    50,		// the minimum level you can learn							
		]) );
	}
}
