// Room: /d/gaochang/room35.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
һ����������¿���һ����̤����һ�ѿݹǡ�����һ�������������������
������ɢ���������Ǻ��ǡ������ֻ���ź󵶺����ۣ��߲���͹������������
��ǰ�У����һ�ѶѰ׹ǣ�ת�˸��䣬ǰ��ͻȻ����һ����
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room36",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/yusword" : 2,
  __DIR__"obj/yuaxe" : 2,
  __DIR__"obj/skeleton" : 6,
  __DIR__"obj/yublade" : 2,
]));

	setup();
	replace_program(ROOM);
}
