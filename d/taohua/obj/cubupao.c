// cubupao.c

inherit EQUIP;

void create()
{
    set_name("�ֲ���", ({ "cu bupao","bupao", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("armor_type", "cloth");
        set("value", 100);
        set("armor_prop/dodge", 1);
		set("armor_prop/armor", 1);
	}
}
