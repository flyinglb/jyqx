// caotangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��λ�����ɽ��´��С�¡���Ժ�е�һ�ڹž�����Ϊ����
������Ϊÿ���峿������һ�ɾ޴�������Ծ����������𣬲�����
�����ˣ�����Ϊ��һ�۴��澰����������һ����᫵�ɽ����������һ
����ɭɭ��С����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southup"     : __DIR__"shanlu7",
//                "north"       : __DIR__"",
        ]));

        setup();
        replace_program(ROOM);
}
