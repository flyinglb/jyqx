// houyuan.c ��Ժ
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������������������һ��Բ�ε��Ŷ�����һ��С·ͨ��
��ɽ��
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "north" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yu" : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
