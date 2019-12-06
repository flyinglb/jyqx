// bowl.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ˮ��", ({ "wan", "bowl" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ˮ�룬������ʲô�أ���Ȼ��ˮ����\n");
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 60);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "water",
                "name": "ˮ",
                "remaining": 60,
        ]) );
}