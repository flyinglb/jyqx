// sword_book3.c

inherit ITEM;

void create()
{
	set_name("华山剑谱", ({ "sword book", "book", "sword_book3" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封面上写著「华山剑法 -- 卷三（高级）」\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"sword",	// name of the skill
			"exp_required":	100000,		// minimum combat experience required
							// to learn this skill.
			"jing_cost":	20,		// jing cost every time study this
			"difficulty":	40,		// the base int to learn this skill
							// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	199,		// the maximum level you can learn
							// from this object.
                        "min_skill":    150,		// the minimum level you can learn							
		]) );
	}
}
