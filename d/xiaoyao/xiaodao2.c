// Room: /d/xiaoyao/xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ��������·
�ľ�ͷ�����԰ٻ����ޡ����������������ϱߺ�������ζɢ��������������
����������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"bingqif",
  "northwest" : __DIR__"xiaodao6",
  "west" : __DIR__"xiuxis",
  "east" : __DIR__"xiaodao1",
  "south" : __DIR__"shantang",
]));
	set("outdoors", "xiaoyao");

	setup();
	replace_program(ROOM);
}
