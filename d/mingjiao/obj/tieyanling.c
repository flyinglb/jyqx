// tieyanling.c ������

inherit ITEM;

void create()
{
        set_name("������", ({"tieyan ling", "tieyan", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����������ƣ��ɽ���ǩ����ƾ�˿�������ս��\n");
                set("material", "steel");
        }
}

