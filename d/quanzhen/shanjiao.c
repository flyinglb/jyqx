// shanjiao.c ����ɽ��
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
����������ɽ��ɽ�ţ�����ɽ�ų������ĵ�һɽ����ɽ�������
�����������ơ������ɽ�ƻ���ƽ����һ��ʯ������ͨ��ɽ�ϡ���ǰ
��һ����ɽ����ͬ����һ���������գ����Թ��˵�ʫ�����С�����
һ������˵����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
//                "northup" : __DIR__"shijie1",
                "north"    : "/d/gumu/shanlu13",
                "westdown" : __DIR__"shanlu4",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
