// dodogbook.c

inherit ITEM;

void create()
{
        set_name("�Ṧƪ", ({ "dodgebook", "shu", "book" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�Ṧƪ\n"
                        "����һ����ʩˮ����Ṧ�ر�����ɫ���ƣ��в��ٵ���ע��\n"
);
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "dodge",        // name of the skill
                        "exp_required": 10000,  // minimum combat experience req
                        "jing_cost":    1,      // jing cost every time study th
                        "difficulty":   20,     // the base int to learn this sk
                        "max_skill":    100     // the maximum level you can lea
                ]) );
        }
}
