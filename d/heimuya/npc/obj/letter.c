// letter.c

inherit ITEM;

void create()
{
        set_name("��", ({"qing xin"}));
        set_weight(100);
        set("value",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ӯӯ�����������顣\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}

