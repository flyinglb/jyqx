// po-bu.c
inherit ITEM;

void create()
{
        set_name("�Ʋ�", ({"po bu", "piece"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���Ʋ���ƾ�˿�ֱ�������Ҫ��������\n");
                set("material", "cloth");
        }
}
