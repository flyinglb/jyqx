inherit ITEM;

void create()
{
	set_name( "舞锤技巧—上册", ({ "hammer_book1" , "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "舞锤技巧-上册\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
                        "name": "hammer",        // name of the skill
                        "exp_required": 10000, // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    99,    // the maximum level you can learn
		]) );
	}
}

