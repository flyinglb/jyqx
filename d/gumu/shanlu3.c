// shanlu3.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ���
���Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£���������������
�ף���ʱ���˺�����������Ҫ��Хһ���������º����ϸ���һ��ɽ·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shanlu2",
                "eastdown"  : __DIR__"shanlu4",
        ]));

        setup();
        replace_program(ROOM);
}
