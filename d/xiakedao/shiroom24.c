// /d/xiakedao/shishi24.c ���͵� ʯ��24

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������谵��ֻ������������ľ������ϥ���ڽ���֮�ϣ����
ʯ��(wall)�������˼����ʯ������ɽ�������ȴ�����ߴ����
���½����ˡ����л�������������Ķ�����֮�ࡣ
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�����̫�������������֡��ֵ��·��̵�����������
������ģ���ǧ�������������������룬����������ֱ��б����
�µĴ�Ƭ�������һ���ѷִ���ίʵ���Ա��ϡ�
WALL
        ]));
        set("objects", ([
                CLASS_D("xiakedao")+"/long" : 1,
                CLASS_D("xiakedao")+"/mu"   : 1,
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
