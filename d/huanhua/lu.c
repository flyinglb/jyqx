// lu.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ����������ʯ·���Ӷ���һֱͨ�����ߣ�һ����ȥ��·
�ľ�ͷ������һ����լ�����԰ٻ����ޡ���������������
LONG
	);
	set("exits", ([
		"west" : __DIR__"damen",
		"east" : "/d/npc/m_weapon/m_room1",
]));
 	set("no_clean_up", 0);
	setup();
}
