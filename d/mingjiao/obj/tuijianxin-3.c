// tuijianxin-3.c �Ƽ��� ��-��

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({"tuijian xin3", "xin3", "letter3"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ������ʹΪ��д���Ƽ��ţ�ƾ�˿�ȥ��������������\n");
                set("material", "paper");
        }
}

