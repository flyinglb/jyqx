// paper.c
inherit ITEM;

void create()
{
        set_name("��ֽ", ({"letter paper", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��������ͨ����ֽ������������Ⱥд�����ѵļҳ��ţ�����д�ã�����\n"
"������˽ӡ������ߵĴ�æ���Ǵ����ˡ�\n");
                set("material", "paper");
        }
}

