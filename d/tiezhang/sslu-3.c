// Room: /u/zqb/tiezhang/sslu-3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
    ������һ������ʯ�̳ɵ�С·�ϡ�����ɽ�Ƶͻ��������˴��̵�
ë������΢�紵�������Ա�����һƬɳɳ����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"sslu-2",
  "northup" : __DIR__"mzfeng",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

