
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ͵꣬��Ϊ�ط�ƫƧ�����ͺ��١���ʱ��
��֮���Ӷ��ϱߴ������ƹ��粻֪���Ķ�ȥ�ˣ����������һ��
�ˡ��ϱ��Ǻ�Ժ��ͨ�����᷿��
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"south" : __DIR__"kedian2",
		"northwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

