inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
	set_name("�������澭���²�", ({ "jiuyin zhenjing2","zhenjing2", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
	"����һ���ñ���д�ɵ��顣���飺�����澭(��)����\n"
	"�ʷ��������ף���������Ů���ֱʡ�\n",
	);
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":       "jiuyin-baiguzhao",
			"exp_required": 10000,
			"jing_cost":  30,
			"difficulty": 20,
			"max_skill":  99,
			"min_skill":  0
		]) );
	}
}
