// Room: /city/taohua2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�һ�Ϫ");
	set("long", @LONG
���һ������һ�Ϫ���һ�Ϫˮ����ϴ�����Ӹ��ƿ����գ����
��Ů����ϡ������������һ�Ϫ������С�����һ����л���ʱ����
����ʱ��ƬƬ�ɺ��׹Ϫ�У���ˮ��ȥ��������ϧ��������Ϫ�ϣ�
����˼�ˣ��������ޡ� 
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);

	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
	]));
	setup();
	replace_program(ROOM);
}

