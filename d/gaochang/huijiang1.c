// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "���׶���ԭ");
        set("long", @LONG
������ɽ����, ���������׶���ԭ��������������, ��·�������һ��
���硣�����ѩ���ڣ����ⰻȻ������ѩ��ֱ��������Ϫ���������Ұ��
����ɽ��ϰϰ������������ˮ��ɽ������, �������Ҳ���ŵ�����Ļ��㡣
����һ���� (ya ) ��ס��������ߡ�
LONG
        );
        set("exits", ([
            "southdown" : __DIR__"huijiang2",
        ]));
        set("objects", ([
                __DIR__"npc/huilang"  : 1,
        ]) );
        set ("item_desc", ([
                "ya" : "������? �������ˡ�\n"
        ])  ) ;
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
