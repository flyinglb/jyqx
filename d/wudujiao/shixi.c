inherit ROOM;

void create()
{
	set("short", "ʯ϶");
	set("long", @LONG
������һ����ʯ�ķ�϶��խ��Ҫ�˲����������������۵��ҷ�
��ǰ��ȥ�����ܺ�����ģ�ֻ�н��µ�ɰʯ������΢�����졣
LONG
	);
        set("no_clean_up", 1);

	set("exits", ([
                "down" : __DIR__"baidu2",
 		"westdown" : __DIR__"mishi",
	]));

	setup();
	replace_program(ROOM);
}
