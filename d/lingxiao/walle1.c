// walle1.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG 
���������ǵĳ�ͷ�����⼫ĿԶ����ֻ������ѩɽ��һƬ��
ã����������֮�£����������ɽ���򶫱��ڶ�ȥ�����ŵ�ѩ��
֮�䣬ֻż������һ������໡�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "east"   : __DIR__"walle2",
                "westdown" : __DIR__"gate",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup();
        replace_program(ROOM);
}

