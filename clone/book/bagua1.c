//bagua1.c
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name(HIC"�����项"NOR, ({ "luoshu","shu", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ���ñ���д�ɵ��顣������ֹ�׭�������顱��\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "count",
                        "jing_cost":  40,
                        "difficulty": 30,
                        "max_skill":  149,
                        "min_skill":  100
                ]) );
        }
}
