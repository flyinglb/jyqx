// huroom.c
inherit ROOM;

void create()
{
        set("short", "ҽ��");
        set("long", @LONG
���߽����һ���Ĵ�Ժ����������Ǹ���������С�ݡ���
�ܰ��˲���ҽѧ�伮�����кܶ�ɢ��ѷŵĸࡢ�衢ɢ�ȡ�һ
����ͷ�ڴ˴��������ƺ����������¡�
LONG );
        set("exits", ([
                "out"     : __DIR__"lhqyuan",
        ]));
        set("objects", ([
                __DIR__"npc/hu" : 1,
        ]));
        set("outdoors", "mingjiao");
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
