inherit ROOM;
void create()
{
        set("short", "ִ����");
        set("long", @LONG
����Ʈѩɽׯ��ִ���ã���ר����������Щ����ׯ���
���ӽ��гͷ��ĵط���
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "south"  : __DIR__"piaoxue2",
        ]));
        setup();
}
