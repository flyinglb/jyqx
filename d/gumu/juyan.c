// juyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ɽ·��Խ��Խ�ա�ֻ��һ�����ʯ����·�У��Կ�ƾ
�٣�����һ���ϸ��������ӣ�����״��ɭ�ɲ�������������η������
�ο��ڴ�פ��ۿ���������һƬï�ܵ����֡���������һ�����͵�ɽ
·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"shanlu8",
                "southdown"  : __DIR__"shulin7",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/ji": 1,
        ]));

        setup();
        replace_program(ROOM);
}
