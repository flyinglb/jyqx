// bupao.c

inherit EQUIP;

void create()
{
    set_name("�಼��", ({ "qing bupao", "bupao","pao", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("armor_type", "cloth");
		set("value", 2500);
		set("armor_prop/dodge", 6);
		set("armor_prop/armor", 1);
	}
}
