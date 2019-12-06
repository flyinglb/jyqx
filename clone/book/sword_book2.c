// sword_book.c

inherit ITEM;

void create()
{
	set_name("��ɽ����", ({ "sword book", "book", "sword_book2" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"������д������ɽ���� -- ��������ף���\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name": 	"huashan-sword",	// name of the skill
			"exp_required":	1000,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	30,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40			// the maximum level you can learn
								// from this object.
		]) );
	}
}
