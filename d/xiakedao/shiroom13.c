// /d/xiakedao/shiroom13.c ���͵� ʯ��13

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ����������ϯ�ض��������Ա�Ŀ���ɣ���Ȼ����������ŵ���
�ơ�һ�������ֳּ��������ڵ������ذ�Ū���ƺ�����ռ����ż��
̧ͷ����ʯ��(wall)����������
LONG );
        set("exits", ([
                "south" : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�������Ȼŵ���������֡��ֵ��·�ȴ�̵���һ����
���ķ��˰���ͼ��������Щ�Ĳ����⡣һ����ע����Ի�����ھ�ʳ��
��禷������������롣����ע�ƣ�����Ի�����鼫���ؾ��ơ�����Щ
׭��Сע��������
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
