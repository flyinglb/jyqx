// /d/xiakedao/shiroom07.c ���͵� ʯ��7

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������������ϰ�书������Ů�Ӷ��Ե������ĵã���ɫ���ص�
������ʯ��(wall)��ϰ�������Աߵ�������������ȴ�����Ի��ƺ�
δ���ž���
LONG );
        set("exits", ([
                "west" : __DIR__"shihole2",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š����˷���ȥ���������֡��ֵ��·��̵������е�һ
��Ů�ӣ��������磬�������������Ҳ���������ơ�����ע�ƣ�С��
���ƣ����޼���ס����һ��ע�����ߣ�����֮����
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
