// Room: /u/zqb/tiezhang/sblu-1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
    ������һ��ʯ���̳ɵ�С·�ϣ������Ǹߴ�Ĵ��������ڽ����� 
������գ�������ˬ���ˡ���ΪСָ�������������˽϶࣬��������· 
Ҳ�����ĺܺá�
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"pubu",
  "eastdown" : __DIR__"shanlu-5",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

