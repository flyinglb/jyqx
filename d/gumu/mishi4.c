// mishi4.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩʫ�䡣
LONG
        );

        set("exits", ([
                "west" : __DIR__"mishi3",
                "east" : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
