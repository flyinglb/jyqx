//lhqyuan.c
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
���߽����һ���Ĵ�Ժ��ȴ���������������У��һ����
�е��ڰ��ҩ���е�����ʯ�ͣ������Ȼ��졣Ժ�����׿���
�����䳡����Լ����������������һ�������������һ����
��᳡���������߾��ǹ����������ܶ��ˡ�
LONG );
        set("exits", ([
                "west"    : __DIR__"lhqlwch",
                "northup" : __DIR__"lhqhoumen",
                "east"    : __DIR__"lhqdating",
                "out"     : __DIR__"lhqmen",
                "enter"   : __DIR__"huroom",
        ]));
        set("outdoors", "mingjiao");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
