// shanlu16.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬����
�Դ䣬���ɽ����֦ͷ���񳪺Ͳ��������Ͽɿ���һ��С�ӡ�����
��ͨ��ɽ�����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "east"  : __DIR__"shanlu15",
                "south" : __DIR__"xiaohebian",
        ]));

        setup();
        replace_program(ROOM);
}
