// Room: /u/mei/room16.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ſ�ջ");
	set("long", @LONG
С�ƼҼ����Ӳ����ȣ����̿���������ϰ��ﳤ�úܲ�������֪Ϊ
ʲô������������壬������һ�����ˡ������ﲼ�õþ��Ŷ����£�ÿһ��
�������Ǿ�����ѡ�ģ����ð�����ǡ���ĵط��������й���һ��������Ԫ��
�Ĳ���ү�����滹�����Ŷ���ĺ조ϲ���֣�����˭�߽���������Կ���
����ط������ˣ�һ�������������ŷ����ε���С�ӡ�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jinxiangyu" : 1,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room2",
]));

	setup();
	replace_program(ROOM);
}
