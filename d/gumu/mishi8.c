// mishi8.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶�������аڷ���һЩ�򵥵ļҾ��þߣ�ԭ��
���ǹ�Ĺ����ʦ�ֳ�Ӣ�ľ��ҡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"mishi7",
                "out" : "/d/city/guangchang",
        ]));

        set("objects", ([
                __DIR__"npc/lin" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
