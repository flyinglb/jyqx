// book2.c

inherit ITEM;

void create()
{
	set_name("����Ƭ", ({ "bamboo", "shu", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long",
			"�׽�Ṧƪ\n"
			"����һƬ����ȥƤ�ľ���Ƭ������ͱ��涼����������������Ծ��Сͼ�Ρ�\n");
		set("value", 500);
		set("material", "bamboo");
		set("skill", ([
			"name":	"dodge",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}
