// ������

inherit ITEM;

void create()
{
	set_name( "���������Ͼ�", ({ "yunlong-jing1", "jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������Ͼ�����Ƥ��һ�������������������֡�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"yunlong-xinfa",	
			"exp_required":	 0,	// minimum combat experience required
			"jing_cost":    20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	49,	// the maximum level you can learn
		]) );
	}
}
