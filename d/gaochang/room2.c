// Room: /u/mei/room2.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������ԭ������ıؾ�֮·�������������ҶӶ�һ��Ҫ�����ﾭ����
�γ�������Ļ���·�ݡ���������Կ���һ���ƾɵĳ��ǣ���������б�
���ں���ĺۼ�������һ��С�ꡣһ�顰[1;37m���ſ�ջ[2;37;0m����ľ�����ƹ������
�ں�����ҡҷ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room3",
  "north" : __DIR__"room16",
  "east" : __DIR__"room1",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room2");

	setup();
	replace_program(ROOM);
}
