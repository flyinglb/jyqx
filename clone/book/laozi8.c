// laozi8.c
// by Marz

inherit ITEM;

void create()
{
	set_name( "���¾����ڰ��¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t�ڰ���\n\n"
			"\t������ˮ��ˮ���������������������֮���񣬹ʼ��ڵ���\n"
			"\t���Ƶأ�����Ԩ�������ʣ������ţ������Σ������ܣ�����ʱ��\n"
			"��Ψ�����������ȡ�\n"
			"\n"NOR
		);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	 0,	// minimum combat experience required
			"jing_cost":    10, 	// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	29,	// the maximum level you can learn
		]) );
	}
}
