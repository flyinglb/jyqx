// Room: /u/zqb/tiezhang/lx.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ");
	set("long", @LONG
������������һ��С����Ȼ�ش�ƫƧ��������������������Ȼ�ܶࡣ��
����һ�乩����Ϣ����С�͵ꡣ���Ϸ���ʮ�ﴦ�����Ǵ˴������ĺ�צɽ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"road-1",
		"north" : __DIR__"hunanroad2",
		"west" : __DIR__"kedian",
	]));
	set("objects", ([
//               "/quest/job/machou":1,
	]));set("no_clean_up", 0);

	setup();
//         replace_program(ROOM);
}

