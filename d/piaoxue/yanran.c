inherit ROOM;
void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
������Ʈѩɽׯ��ׯ������Ȼ���޵����Ȼ��ǰ
��ׯ���ķ��ˣ�����Ĳ���ȫ�Ǽ���Ȼ�������õġ�
LONG );
	set("no_steal", "1");
	set("sleep_room", "1");
	set("no_clean_up", 0);
	        set("exits", ([
                "west"  : __DIR__"piaoxue3",
        ]));
        setup();
}