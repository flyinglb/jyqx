// guanritai.c ����̨
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����������ɽ�ϵĹ���̨����֪�ĳ��Ĵ��������������������
ƽ̨��������հ�ճ��������������ɽ�Ʒǳ�����������һ��������
���������°���Ʈ�����治֪���ںξ���
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
