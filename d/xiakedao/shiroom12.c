// /d/xiakedao/shishi12.c ���͵� ʯ��12

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��Լ�ǵ��������ڴ�ʯ��֮�ʣ����������վ�˲����ˡ�����
������һ����ɮ�ֳִ󻷵�������֮����������������������������
����¡��������µ����걳��ʯ��(wall)���ƺ����ǳ�����
LONG );
        set("exits", ([
                "east"  : __DIR__"shihole3",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�����Ȱ�������������֡������ͼȴ����ʫ�����
��ɡ��ǻ�����һ���ֲֳ񵶵��Է򣬱��ϼ���¡�𡣼�ʮ��ľ���
���ֱ�����ҵ�ɢ��������ǰ��ͼ�������������ܵ�������Сע��
WALL
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
