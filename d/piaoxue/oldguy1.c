inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
����Ʈѩɽׯ�ĳ���Ժ���Ǹ����ϻ����Ǿۼ����µĵط���
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"piaoxue2",
        ]));
        setup();
}
