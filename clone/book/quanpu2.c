// quanpu2.c

inherit ITEM;

void create()
{
	set_name( "��ȭʮ�ν�",({ "changquan_book", "shu","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long","����һ���䵱�ɴ��˻ưټ�������ȭ��������\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
                        "name": "unarmed",  //name of the skill
                        "exp_required": 100000 , //minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	199,	// the maximum level you can learn
			"min_skill":	99	// the minimum level you can learn
		]) );
	}
}
