// parry-book.c

inherit ITEM;

void create()
{
	set_name( "�м�����",({ "parry-book1","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long","����һ���߽�����ʦд�Ĺ��������мܵ��鼮��\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
                        "name":         "parry",      //name of the skill
                        "exp_required": 1 ,           //minimum combat experience required
			"jing_cost":    10+random(10),// jing cost every time study this
			"difficulty":	10,           // the base int to learn this skill
			"min_skill":	0,            // the minimum level you can learn
			"max_skill":	29            // the maximum level you can learn
		]) );
	}
}
