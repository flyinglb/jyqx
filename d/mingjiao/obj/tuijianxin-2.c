// tuijianxin-2.c �Ƽ��� ��-��

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({"tuijian xin2", "xin2", "letter2"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ������Ϊ��д���Ƽ��ţ�ƾ�˿�ȥ������������ʹ��\n");
                set("material", "paper");
        }
}

