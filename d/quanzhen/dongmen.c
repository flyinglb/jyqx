// dongmen.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书��Ķ��ţ���ǰ��ǽ���ʣ�ǽ�ϵļ����������
��������ȥ��������������ǽ�����������׹⣬�ƺ��Ǳ��������
�Ĺ⡣���������š����š��������֣��ſ�վ��һЩ�ٱ������ֳ�
���������������������ǡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"guandao2",
                "west" : __DIR__"dongjie",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
