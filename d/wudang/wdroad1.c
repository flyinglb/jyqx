// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������Ҵ�
���������������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�����
��һ��Ƭ���֡�
LONG );
        set("outdoors", "wudang");
        set("exits", ([
                "south"     : __DIR__"wdroad2",
                "north"     : "/d/city/nanmen",
                "west"      : __DIR__"work",
                  "east" : __DIR__"work1",
        ]));
//         set("objects", ([
//                "/u/jimo/quest/gongtou" : 1,
//       ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( dir=="west" && !wizardp(me) )
                return notify_fail("���ﻹû���š�\n");
        return ::valid_leave(me, dir);
}

