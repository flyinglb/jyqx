// tuijianxin-4.c �Ƽ��� ��-��

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({"tuijian xin4", "xin4", "letter4"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ������Ϊ��д���Ƽ��ţ�ƾ�˿�ȥ�����̷�����\n");
                set("material", "paper");
        }
}

