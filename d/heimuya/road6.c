// road6.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "����·");
	set("long", @LONG
������һ������·�ϡ������ĵ��棬���ǿ������Ļ�������
�Ϸ�����ԶԶ�и�ɽ���ƣ����������и�СС���䡣��������Ȯ
�ͼ��䣬���㳤;�ı�������һ˿������
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "southeast" : "/d/village/wexit",
                "north"     : __DIR__"road5",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
