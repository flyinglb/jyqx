// mishi5.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ���š�
LONG
        );

        set("exits", ([
                "south" : __DIR__"mishi3",
                "north" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
