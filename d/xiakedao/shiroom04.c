// /d/xiakedao/shiroom04.c ���͵� ʯ��4

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�˶������ǽ�Ϊӵ�����м��˽�̤�������Ƿ�λ�������������
�ߣ�һ�����߶����ڱ�����λ��Ŀ������ͷ������͸��˿˿��������
��������Ů�Ӳ����������ʯ��(wall)��ָָ��㡣
LONG );
        set("exits", ([
                "east" : __DIR__"shihole1"
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š��������ǡ��������֡��ֵ��·�����һ�ŻƵ���
��ͼ�����б������Ǵ�����ԡ�����ͼע�����ơ����ǡ���Ȼ���Ӿ�
�������᱾��ĩҲ����һ��Сע����ѩ�ƽ����쪡�
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
