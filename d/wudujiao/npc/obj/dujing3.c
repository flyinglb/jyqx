// dujing3.c

inherit ITEM;

void create()
{
	set_name("������ƪ", ({ "jing", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ᣬ�������������д���˸����ö��ķ����Ͷ�ҩ���䷽��\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":	"duji",	// name of the skill
			"exp_required":  100000,// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	150	// the maximum level you can learn
		]) );
	}
}
