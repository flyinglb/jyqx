// yunu_sword.c

inherit ITEM;

void create()
{
	set_name("��Ů����", ({ "yunu-sword-book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"������д������Ů���� ��\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":		"yunu-sword",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	30,			// jing cost every time study this
			"difficulty":	30,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40			// the maximum level you can learn
								// from this object.
		]) );
	}
}
