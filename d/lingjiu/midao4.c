
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
̨�������ߵ���ͷ����ǰ��һ��СС��ʯ�ң���Χǽ���ϲ��ż�յ��
�ƣ��յ�ʯ����һƬ��ơ�������һ��ͨ����
LONG );
	set("exits", ([
		"westup" : __DIR__"midao3",
		"north": __DIR__"midao5",
	]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
