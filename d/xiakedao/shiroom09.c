// /d/xiakedao/shiroom09.c ���͵� ʯ��9
inherit ROOM;
int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������ʯ�������Ϊ���ơ���ʯ�������ǰ�����һ����״�
��һ����ʿ��Զ��������ڻ��������֡�һ��վ��Զ��ǽ�ǣ���ǽ��
�Ļ��ȡ�����������У�������ʯ��(wall)�������ƺ��Ѿ�������ȥ��
LONG );
        set("exits", ([
                "south" : __DIR__"shihole3",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š��й����������������֡��ֵ��·��̵����ǡ�����
�С�ʫ���������ƵĹ��¡�ֻ��һ�˽�ü���ޣ��߹ڻ�����ȴ������
�����㣬���ʿ�֪�������; ��һ�˸��ݰ��룬���Ǻ�������������
��Ӱ����������ͼ��֮��Сע������
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
