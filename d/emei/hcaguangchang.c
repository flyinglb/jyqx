// Room: /d/emei/hcaguangchang.c

inherit ROOM;

void create()
{
	set("short", "�����ֹ㳡");
	set("long", @LONG
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ����
�۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "emei");
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"hcawest1",
  "southup" : __DIR__"hcadadian",
  "north" : __DIR__"hcazhengdian",
  "south" : __DIR__"wuchang",
  "east" : __DIR__"hcaeast1",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/kungfu/class/emei/xu" : 1,
]));
	set("valid_startroom", "1");

	setup();
	replace_program(ROOM);
}
