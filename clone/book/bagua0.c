//bagua0.c
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name(HIC"����ͼ��"NOR, ({ "hetu","tu", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ���ñ���д�ɵ��顣������ֹ�׭������ͼ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "count",
                        "jing_cost":  25,
                        "difficulty": 20,
                        "max_skill":  69,
                        "min_skill":  40
                ]) );
        }
}
