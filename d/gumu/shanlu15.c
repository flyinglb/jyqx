// shanlu15.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬����
�Դ䣬���ɽ����֦ͷ���񳪺Ͳ����������Ͷ��Ͽ�ͨ��ɽ�����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southeast" : __DIR__"shanlu14",
                "west"      : __DIR__"shanlu16",
        ]));

        setup();
        replace_program(ROOM);
}
