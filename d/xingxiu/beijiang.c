// /d/xingxiu/beijiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ��ά�����۾ӵ�С����������������ʮ�����֡�ֻ��
����˵�Ļ����������������м�С���̣��������������У������ھ���
ʲô�����������м�Ժ�䣬Ժ�ſ��пô�����������һ����ǡ�
LONG );
        set("exits", ([ 
            "west"      : __DIR__"store",
            "east"      : __DIR__"house",
            "north"     : __DIR__"majiu",
            "northwest" : __DIR__"saimachang",
            "southeast" : __DIR__"shanjiao",
        ]));
        set("objects", ([
                __DIR__"npc/woman": 2 ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

