// Room: /d/xiangyang/shudian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������ϰ�մ�������������˵��ǰ��������ɽ�����³�
���ң���֪ʲôԭ���ֻ����ף�ר������Ϊ����ֻ�������
���ܴ���ǰ����һ��������
LONG );
	set("exits", ([
		"east" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/shudianboss" : 1,
	]));
	setup();
	replace_program(ROOM);
}
