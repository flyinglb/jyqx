// /d/xiakedao/shiroom16.c ���͵� ʯ��16

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ű����ü��ٵĺ���֮����ֻ��һ������ʯ��(wall)��������
ͷ�ʶ�����Ϣ�����������������˽�Ҫ��ͷ����һ����˫�ư���ǰ
�˵ĺ��ģ�ͷ��Ҳ�ǰ����뵡�
LONG );
        set("exits", ([
                "east"  : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
����ǽȴ�����洦�������������������������������档���Ͽ̵���
������װ��Ů����̬��˳��ӯ������бб��һ��ע��������ʫ������
ܱ�Ķ�������������������������һ��ע�ּ��ʲݣ��������Ҳ�ա�
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
