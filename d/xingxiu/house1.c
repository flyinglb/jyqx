// /d/xingxiu/house1.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "�����ҿ���");
        set("long", @LONG
���ǰ����ҵĿ������������Ų�˹��̺��ľ���ϰ�����ԭ�Ĵ��������ó�
��ҵ�����һ������Ǯ��
LONG );
        set("exits", ([ 
            "west" : __DIR__"house",
        ]));
        set("objects", ([
                __DIR__"npc/afanti": 1
        ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

