// jiuping.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(GRN"��ƿ"NOR, ({"jiuping", "bottle"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ө���̵ĵĴ��ƿ��װ��ѬѬ���˵ĸ����Ͼơ�\n");
                set("unit", "��");
                set("value", 200);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "�����Ͼ�",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}
