// Room: /u/mei/room67.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��ǰ���Ǹ����Ž��صĴ�ȣ��컨������������ӳ������������
����������ܸ�ɽ���ƣ��ƺ�ب��������δ���˼�����������ѩ���
�ƣ��վ����ͣ������޷���Ԯ���롣
LONG
        );
        set("objects", ([ 
  __DIR__"npc/monkey" : 2,
]));
        set("exits", ([ 
  "west" : __DIR__"room68",
  "north" : __DIR__"room70",
]));

        setup();
        replace_program(ROOM);
}
