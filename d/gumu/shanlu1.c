// shanlu1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ���
���Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£���������������
�ף���ʱ���˺�����������Ҫ��Хһ������������һƬ�յء�������
��������ɽ���塣
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southdown" : __DIR__"kongdi",
                "northup"   : __DIR__"zhufeng",
        ]));

        setup();
        replace_program(ROOM);
}
