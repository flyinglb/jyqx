// Room: northroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������Ǳ�����ˣ�����������һ�ֵֹֹ���ζ������̫���š�
·�ܿ�����ȴ���࣬�������ڻƻ��Ժ���������һ����֣�����
�ִӴ�һֱ������������һ�ұ����̣������������˶����ޱ��飬��
��������
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"       : __DIR__"northroad2",
	    "southwest"  : __DIR__"westroad3",
	    "northwest"  : __DIR__"bingqidian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
