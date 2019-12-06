// book-stone.c

inherit ITEM;

string* skills = ({
	"finger",
	"claw",
	"strike",
	"cuff",
	"hand",
});

void create()
{
	int i = random(sizeof(skills));

	set_name("ʯ��", ({ "stone", "shu", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�׽ȭ��ƪ\n"
			"����һ��԰԰��ʯ�壬�ƺ�����ָ�̻�������ָӡ��\n");
		set("value", 500);
		set("material", "stone");
		set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}
