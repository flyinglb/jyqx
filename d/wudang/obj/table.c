//table.c ������
inherit ITEM;
void create()
{
        set_name("������", ({ "table" , "zhuo zi"}) );
        set_weight(5000);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���������ӷ������˵�����Ĺ��졣\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

