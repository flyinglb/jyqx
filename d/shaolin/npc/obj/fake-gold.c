// fake-gold.c

inherit ITEM;

void create()
{
	set_name("�ƽ�", ({"gold", "ingot", "gold_money"}));
	set_weight(150000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����� ...��ɫ�е㲻�ԡ�\n");
		set("unit", "��");
		set("material", "lead");
	}
	setup();
}

