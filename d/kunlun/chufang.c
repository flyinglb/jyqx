//Robin 2000.5.9

inherit ROOM;

void create()
{
	set("short","�����");
	set("long", @LONG
��ν����������ǹ����ڶ��˳Է��ĳ���������������լ�ڵ�һ��������
�����������˼��ھ���ճ���ʳ�����µ����ǲ��ܵ�����Է��ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chushi1" : 1,
	]));
	set("size",2);

	setup();
	replace_program(ROOM);
}
