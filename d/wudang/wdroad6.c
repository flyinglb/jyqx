//Room: wdroad6.c
//Date: Feb.12 1998 By Javw

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������������ڵ�һ�������ĵĻ���·��������ЩС���ݣ���������
�ġ�·�����˺��٣�����ɫ�Ҵҵ���ǰ��·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
//            "north"      : "/d/village/hsroad1",
            "south"      : __DIR__"house",
            "southeast"  : __DIR__"wdroad5",
            "west"       : __DIR__"wdroad7",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

//������һ��С��ׯ��
//����С�����������ɽ�ˡ�

