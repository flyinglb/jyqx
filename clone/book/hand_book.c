// hand_book.c

inherit ITEM;

void create()
{
	set_name("����", ({ "qi_pu", "pu" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ᣬ�������������д����ӬͷС�����������\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	   "hand",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}
