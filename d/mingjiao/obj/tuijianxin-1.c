// tuijianxin-1.c �Ƽ��� ̳����

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({"tuijian xin1", "xin1", "letter1"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��̳��Ϊ��д���Ƽ��ţ�ƾ�˿�ȥ������ʹ�ߡ�\n");
                set("material", "paper");
        }
}

