// letter.c
inherit ITEM;

void create()
{
        set_name("����", ({"hand letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ǻ�ɽ����������Ⱥ�����ţ���������Ѵ�õı�������ִ�ŵ��ӡ�\n");
                set("material", "paper");
        }
}

