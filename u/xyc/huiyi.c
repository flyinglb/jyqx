inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���Ǻ��ֳ�Աƽʱ����ĵط����������кܶ�������صĴ���
��������������ġ������м����һ��ľ������Χ��������ӡ���
���Ϸ���һ�ײ�ߣ�����豭���Ա�����ʱƷ��֮�á�
LONG );
        set("no_sleep_room", "1");
        set("no_fight","1");
        set("no_steal", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "north"  : __DIR__"yegong",
                "west"  : __DIR__"yegong2",
                "east"  : __DIR__"xiaogong",
                "south"  : __DIR__"dating1",
        ]));
        setup();
        "/u/xyc/heishou_b.c"->foo();
}
