// shanlu13.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�������������������
����ʥ�ء������������ɽ���������������أ�����Խʮ���أ�
����˰����������������ɽ֮�ơ������ɿ���һ������������
һ��ͨ�����ֵ��ľ�С·��������������ɽ.
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup"   : __DIR__"shanlu12",
                "east"      : __DIR__"puguangsi",
                "west"      : __DIR__"shanlu14",
                "south"     : "/d/quanzhen/shanjiao",
        ]));

        setup();
        replace_program(ROOM);
}
