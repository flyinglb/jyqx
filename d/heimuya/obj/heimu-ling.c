// heimu-ling.c ��ľ��

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(BLK"��ľ��"NOR, ({"heimu ling", "heimu", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ǿ�ݽ��ĺ�ɫľͷ����Լ��ߣ���
�����л������֣�����ʮ�ֹ��졣\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "wood");
        }
}

