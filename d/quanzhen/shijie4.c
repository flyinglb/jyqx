// shijie4.c ʯ��
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�
����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ���
��Ѿ����Կ���ȫ��������۵��ܽ��ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie5",
                "westdown" : __DIR__"shijie3",
                "southup" : __DIR__"shijianyan",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
