inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ʈѩɽׯ�Ļ����ã���Ʈѩɽׯ��λ�������ĵط���
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "north"  : __DIR__"piaoxue2",
        ]));
        setup();
}
