// huaping.c ��ƿ

inherit ITEM;

void create()
{
        set_name("��ƿ", ({ "bottle", "hua ping", "bag" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����觻�ƿ��ƿ�ϵ����һ֦����ĵ����\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

