// mishi6.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ����
LONG
        );

        set("exits", ([
                "east" : __FILE__,
                "north" : __DIR__"mishi3",
                "south" : __DIR__"mishi7",
                "west" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
