inherit ROOM;
void create()
{
        set("short", "ǰԺ");
        set("long", @LONG
��������ָɽׯ��ǰԺ���൱�������ҿ�ǽ�����м���Ͱ�
��ƽ�������Ǽ��˵�ס������ǰ��������ľ��������紵������Ҷ
�������¡���ľ��������һ�������
LONG );
        set("no_sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"shufang",
                "east"  : __DIR__"lgong",
                "out"  : __DIR__"damen",
                "north"  : __DIR__"dating1",
        ]));
        setup();
}
