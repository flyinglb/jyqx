// menghan_yao.c

inherit COMBINED_ITEM;

void create()
{

	set_name("�ɺ�ҩ", ({ "menghan yao", "yao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"���Ǽ���ͨ���ɺ�ҩ. \n" );
		set("unit", "��");
		set("pour_type","slumber_drug");
		set("base_value", 700);
		set("base_unit", "��");
		set("base_weight", 30);
	}
	set_amount(1);
}

