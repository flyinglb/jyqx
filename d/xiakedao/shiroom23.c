// /d/xiakedao/shiroom23.c ���͵� ʯ��23

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ�������������ţ���������������һ�ˣ�����һ����ɫ���Ƶ�
Ů�Ӷ��ơ���Ů����������������������Ͼ��ʱ�һ��ʯ��(wall)��
���ŵ�����Ҳ���������ơ�һ�������ֱֳ�ī���ڵ�����д��Ĩ��ҡ
ͷ���Եغ��ǵ��⡣
LONG );
        set("exits", ([
                "west" : __DIR__"shihole6",
        ]));

        set("item_desc", ([
                "wall" : @WALL
�������֡�˭������¡����Ҳ�ֱ�š����ͼ�ϻ����һ���������ߣ�
���Զ������١�ֻ�����������ң�����������ϵ�΢ЦҲ�������š�
һ�е�����ע�ƣ��������¾��У��ս����������顣��ע�������¾���
�ƣ����ߵ�֮�������ߵ�֮�á�
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
