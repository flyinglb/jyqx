// giftbox.c ��Ʒ��

inherit ITEM;

void create()
{
        set_name(HIR"��Ʒ��"NOR, ({ "giftbox", "box" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ʒ�С�����װ����ʦ���������\n\n    "HIR"������֣���\n\n"NOR);
                set("value", 0);
        }
}

int is_container() { return 1; }

