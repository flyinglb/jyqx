// Room: /u/zqb/tiezhang/hhyuan-1.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
    ����һ���������ŵĻ�԰��ֻ���������񣬲Դ���죬������� 
 ��������������һ����ɽ�������Ǵ�Ƭ�Ļ��ԡ�������ͨ��ɽ�ϵ�·��
LONG	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shanlu-3",
  "south" : __DIR__"hxfang",
  "west" : __DIR__"hhyuan-3",
  "east" : __DIR__"hhyang-2",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

