inherit ROOM;
void create()
{
        set("short", "Ʈѩ¥��¥");
        set("long", @LONG
������Ʈѩɽׯ����λׯ��ס�ĵط��������Ǹ�ׯ������Ȼ
���޵������ׯ���������޵��������������ׯ����
�û��Ǿ����뿪���������������˿ɲ���ʲô��������顣
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	        set("exits", ([
                "east"  : __DIR__"yanran",
                "west"  : __DIR__"haiyao",
                "down"  : __DIR__"piaoxue2",
        ]));
        setup();
}