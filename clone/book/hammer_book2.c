inherit ITEM;

void create()
{
	set_name( "舞锤技巧—下册", ({ "hammer_book2" , "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "舞锤技巧-下册\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
                        "name": "hammer",        // name of the skill
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "min_skill":    99,    //  the minimum level you can learn
                        "max_skill":    199,    // the maximum level you can learn
		]) );
	}
}

