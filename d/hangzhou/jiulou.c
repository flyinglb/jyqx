// jiulou.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "¥��¥");
        set("long", @LONG
����¥��¥����Բ�������˲�֪�������ʽ�����Ǻ���һ����
���κ������Ƕ�һ���������ﳢ�������������ֺ��ļ����˸�ʽ��
�ȡ���С��������ȥ��æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��
LONG);
        set("exits", ([
            "west"      : __DIR__"road10",
//            "up"        : __DIR__"loveroom",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" : 1,
        ]));
        set("item_desc", ([
            "paizi" : "
������(Pork)      ��һ�������ֶ�ʮ��ͭ��
��������(Fish)    ��һ�������ֶ�ʮ��ͭ��
�ٹ��Ͱ�(Baozi)   ����ʮ��ͭ��
����Ϻ��(Shrimp)  ����ʮ��ͭ��
�л�ͯ��(Chicken) ��һ�������ֶ�ʮ��ͭ��
��������(Guihua geng)��һ�������ֶ�ʮ��ͭ��
��ƿ(Jiuping)     ��ʮ��������\n",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

