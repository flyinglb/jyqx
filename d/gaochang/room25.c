// Room: /u/mei/room25.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�߲�����");
	set("long", @LONG
��Ȼ����ǰһƬ�տ�����ʱ����������ֻ����ɫ������Ī����״��һ��
����ɽ�������𣬷�ǰһ���ŵĶ��Ƿ��ݡ�ǧ�������ݶ�ԫʣ�ߣ����Ʋ�
������ûһ����������������ģ��������ʣ��ɼ�������һ��ʮ�ַ���
�ĳ��С�
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room25");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room24",
  "west" : __DIR__"room26",
]));

	setup();
	replace_program(ROOM);
}
