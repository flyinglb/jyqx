// mishi3.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩͼ�Ρ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"mishi4",
                "north" : __DIR__"mishi5",
                "south" : __DIR__"mishi6",
                "west" : __DIR__"mishi2",
        ]));

        setup();
        replace_program(ROOM);
}
