//yijing1.c

inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name(HIY"���׾�˵��ƪ��"NOR, ({ "yijing shuogua","yijing1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ���ñ���д�ɵ��顣���飺���׾�˵��ƪ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "qimen-wuxing",
                        "jing_cost":  25,
                        "difficulty": 20,
                        "max_skill":  50,
                        "min_skill":  25
                ]) );
        }
}
