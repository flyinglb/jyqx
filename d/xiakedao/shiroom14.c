// /d/xiakedao/shiroom14.c ���͵� ʯ��14
inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������������ˮ��ʱ����ͷ����ʯ���ϵ��£�������Щù����
ʯ���յ����������Ͽ̵���ͼ���֡��Ҳ�һλ����ؤ���ڶ��Ŷ���ʯ
��(wall)��ȭ��ȭ��ʮ�㡣
LONG );
        set("exits", ([
                "north" : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
����ǽ���ּ�ȴ���ڲ�ͬ���������֡�������Ϊ�᡹�������С��ڴ�
�ֵıȻ��м䣬�����ܵ�һ�ζ�Сע����ǳ��һ��ԶԶ��ȥ��ȴ����
��ͼ����ʶ��һ��ע�ǣ���Ի��ɽ�������𣬾����Գͷ�������
WALL
        ]));
        set("objects", ([
                __DIR__"master/hong"   : 1,
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
