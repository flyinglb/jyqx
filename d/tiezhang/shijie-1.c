// Room: /u/zqb/tiezhang/shijie-1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
    һ��ʯ���������£���ʧ��ŨŨ�ĺڰ��С�ʯ���ϳ�������ɫ�� 
��̦���������š�Զ���ڰ��ľ�ͷ�ƺ��е��ƵĹ�����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
"out" : __DIR__"wmfeng",
  "eastdown" : __DIR__"shijie-2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

