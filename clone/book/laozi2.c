// laozi2.c

inherit ITEM;

void create()
{
	set_name( "���¾����ڶ��¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t�ڶ���\n\n"
			"\t���½�֪��֮Ϊ����˹���ѡ���֪��֮Ϊ�ƣ�˹�����ѡ�\n"
			"\t����������������ɣ��������Σ�������ӯ��������ͣ�ǰ����\n"
			"�档��Ҳ��\n"
			"\t����ʥ�˴���Ϊ֮�£��в���֮�̣�����������ʼ���������У�\n"
			"Ϊ�����ѣ����ɶ����ӡ���Ψ���ӣ����Բ�ȥ��\n"
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
