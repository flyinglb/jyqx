// allow-letter.c ����

inherit ITEM;

void create()
{
        set_name("����", ({"shou yu", "yu", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ɷ���ǩ�������ͣ�ƾ�˿����ɽ���ؾ����¥��ϰ�ϳ��书��\n");
		set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}

