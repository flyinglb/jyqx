//Room: wdroad7.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ�������ĵĻ���·��������ЩС���ݣ���������ġ�·������
���٣�����ɫ�Ҵ���ǰ��·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
            "east"      : __DIR__"wdroad6",
            "southwest" : __DIR__"wdroad8",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


