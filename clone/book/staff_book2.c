// staff_book.c

inherit ITEM;

void create()
{
        set_name( "�ȷ�ͨ�⣨�£�", ({ "staff_book2" , "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��С��д�ɵ��飬���滭�����ȵ�С�ˡ�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
                        "name": "staff",        // name of the skill
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    199,    // the maximum level you can learn
                        "min_skill":    99,	// the minimum level you can learn							
		]) );
	}
}

