// Room: /d/suzhou/shuyuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλ�Ϸ�������̫ʦ
���Ͻ�ѧ��������������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸����
����ǰ�棬���ϰ��ż��������˵���װ�鼮��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"nandajie1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jiaoxi" : 1,
	]));
//	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
