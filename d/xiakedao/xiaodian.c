// Room: /d/xiakedao/xiaodian.c
// xiao dian in xiakedao
// YZC 1995/12/04
// arnzh 97/1/24
inherit ROOM;

void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
���С�Ե겼�ü��ף��տյ�ʯ��ʲôҲû�У�������ȴ�ܺá�
�˿Ͷ��ǴҴҵĽ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
LONG );
        set("exits", ([
                "west" : __DIR__"yingbin",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

