// Room: /u/mei/room5.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "��ԭ");
	set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��
������������Ⱥ����������Ʈ���Ķ����ơ�Զ��������ɽ�ڽ����¿���
���紿��������Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ���û�뵽���������
����֮�ؾ����������ĵط������ûԻͶ����أ����������Ի���������
�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room6",
  "east" : __DIR__"room52",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room5");

	setup();
	replace_program(ROOM);
}
