// honghua.c
inherit ITEM;

void create()
{
        set_name("���Ǻ컨", ({ "honghua" , "���Ǻ컨"}) );
        set_weight(5);
        set_max_encumbrance(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long", "һ���ʺ�Ļ���\n");
                set("value", 1);
        }
}

