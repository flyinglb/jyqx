// Room: /u/zqb/tiezhang/shanjiao.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
    �����ѵ���ɽ���£��˴���������������ɽ����أͻŭ��ȷ����
����ָ�����ڰ��֮�С�����һ���ȼ�ͦ�Σ�����ָ�죬�����Ʊ�������
����ɽ������һƬ���֣�������ѩ������������������������缫�ҡ�
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanmen",
  "southeast" : __DIR__"road-3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

