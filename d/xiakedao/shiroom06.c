// /d/xiakedao/shiroom06.c ���͵� ʯ��6

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ʯ����ȴǡ�����˹ۿ�ͼ�ף��˵����������壬���ڴ�����
����������ǽ�ϻ�Ѿ�����ȼ���ţ�ż��������΢�ıϲ�֮��������
��������֬����ζ��ʯ��(wall)Ҳ��Ѭ���˼�����
LONG );
        set("exits", ([
                "north" : __DIR__"shihole2",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�ǧ�ﲻ���С��������֡��ֵ��·�����ͼ��������
һ����ͨ�������Զ��һ�����������֣������̳����𣬽�������
���е�����֯��һƬ���Աߵ�ע�����࣬һʱҲ���ϲ��塣
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
