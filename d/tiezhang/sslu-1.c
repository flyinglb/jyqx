// Room: /u/zqb/tiezhang/sslu-1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
    ������һ������ʯ�̳ɵ�С·�ϡ�����ɽ�Ƶͻ��������˴��̵�
ë������΢�紵�������Ա�����һƬɳɳ����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"sslu-2.c",
  "westdown" : __DIR__"pingtai",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

