// Room: /u/mei/room50.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ͱ�");
	set("long", @LONG
�е���һ����ɽ֮�ֻ࣬����ɽ�����ͱ�֮�ϣ��������亣������滨��
������̣����ܶ��ǻ�ѩ������ӳ�̣�����Ϧ�����ӳ�գ����޻�����������״��
�ŵ��������㣬���ͱ���Ʈ���������ǻ����Լ�ж�ʮ���ɣ���Ȼ��˷ҷ������
�������֮Ũ�������ͱڣ�������Ȼ����������ɭ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"room53",
  "eastdown" : __DIR__"room49",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room50");

	setup();
	replace_program(ROOM);
}
