// minju4.c ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���������һ�����Ϳ����ݽǴ��С���ض�������ʳ�����ó�����
����ճ�ȷʵ������������һλ������Ц�����ؿ����Լ��Ļ�����
Ҳ������������������ֲ����ˡ�
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"guchang",
        ]));

        set("objects", ([
                __DIR__"npc/cunmin" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
