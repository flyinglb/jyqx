// guijia.c �ڹ��
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB"�ڹ��"NOR, ({"gui jia","jia"}));
        set_weight(800);
        set("unit", "��");
        set("long", "����һ���ڹ�ף������и��ֻ��ƣ�����������ҩ��\n");
        setup();
}

