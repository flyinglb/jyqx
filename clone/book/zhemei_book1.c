// ��ɽ��÷�ַ�ͼ

inherit ITEM;

void create()
{
	set_name( "��ɽ��÷�ַ�ͼ�Ͼ�", ({ "shoufa tu1", "tu1" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɽ��÷�ַ�ͼ�����滭��һЩ�׷����ӵ���ʽ��\n");
		set("value", 500);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"zhemei-shou",	
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":    20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	49,	// the maximum level you can learn
		]) );
	}
}
