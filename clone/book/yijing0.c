//yijing0.c

inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name(HIY"���׾�����ƪ��"NOR, ({ "yijing xugua","yijing0", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ���ñ���д�ɵ��顣���飺���׾�����ƪ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "qimen-wuxing",
                        "jing_cost":  20,
                        "difficulty": 20,
                        "max_skill":  25,
                        "min_skill":  0
                ]) );
        }
}
