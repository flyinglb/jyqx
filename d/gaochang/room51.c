// Room: /u/mei/room51.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
Զ��������һĨ���͡�ת��֮�䣬ʯ��Խ��Խ����һ���ſ���ֱ���ȥ��ɽ
ʯ�����힅�����ƺ����б�����أ����߽�ʱ�������ͱ��м�¶��һ����������
ɽ��ֱ�߽�ȥ�����Ǹ���ͻؽ�֮��Ľ�ͨ�׵�����Ͽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room52",
  "east" : __DIR__"room4",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room51");

	setup();
	replace_program(ROOM);
}
