// riyueyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ֻ����ͺͺ��ɽ·���ԣ���ʯ��������Ϊ���ˡ�����
��ǰ����Զ���������ʯ����ߵ�һ�����������ұߵ��ǿ���̫����
�е�����������һ������ֻ������һ����Լһ�˶��С��������ͨ
���������ºͱ����߶���һ�����ѵ�ɽ·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "eastdown"  : __DIR__"shanlu10",
                "northup"   : __DIR__"shanlu9",
        ]));

        setup();
        replace_program(ROOM);
}
