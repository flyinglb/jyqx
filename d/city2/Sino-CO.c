// Room: /d/city2/Sino-CO.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����棬��������̶��������ڴ�Ҷ��ǵ��������ĳ��һ��
���������Ƕ���һ���棬�β���������?��ͬΪMUD�ķ������㹱�ס�������
�ݽ���͵�����!
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"lab",
		"south" : __DIR__"ximenwai",
		"east" : __DIR__"domitory",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
