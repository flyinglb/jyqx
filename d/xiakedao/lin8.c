 // Room: /xiakedao/lin8.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����߳������֣��㲻�����������˿��������������������
�����ϣ�ʹ��е��ޱȵ���ů���ϱ���һ�����ʵ�ʯɽ��ɽ������
�Բԣ�������ľ��
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
              "south" : __DIR__"shanmen",
              "north" : __DIR__"lin7",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
