// xuanfeng_book.c

inherit ITEM;

void create()
{
        set_name( "����ɨҶ�ȷ�", ({ "xuanfeng-leg-book", "paper" , "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", 
"��������ֽƬ������д�Ķ��������Ŀھ�Ҫּ��ȴ�ǻ�ҩʦ��
�ױʣ��ּ��پ�ͦ�Σ���һҶ������д����Ŀ���ǡ�����ɨҶ
�ȷ������֡�\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
                        "name": "xuanfeng-leg",        // name of the skill
                        "exp_required": 1000,  // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    99,     // the maximum level you can learn
                        "min_skill":    30,     // the minimum level you can learn
		]) );
	}
}

