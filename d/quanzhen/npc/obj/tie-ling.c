// teie-ling.c
inherit ITEM;

void create()
{
	set_name( "������", ({ "chongyang ling", "ling", "iron" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ������ͨ�����������������ơ� �ɵ�������ǩ��������·Ӣ���빬����\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
}

void init()
{
        call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
