// Room: /d/xiangyang/guofuwoshi.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǹ����ͻ��ص����ҡ�������ĳ���ܼ򵥡��ŵ�
�����һ���������ϵı��챻�����������롣��ͷ���Եĵ�
������һ����ױ̨�����ϰ���һ��������ͭ����ͭ���ԱߵĻ�
ƿ���һ���ٺϻ�������ɢ�������������㡣��߷�������
ľ�Σ��м���һ�輸���������һ��ɽ�軨��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"guofuhuayuan",
	]));
	setup();
	replace_program(ROOM);
}

