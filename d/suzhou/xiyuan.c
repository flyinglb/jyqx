// Room: /d/suzhou/xiyuan.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","Ϸ԰��");
	set("long",@LONG
����һ�����ݳ��ﶦ��������Ϸ԰��Ϸ԰��������������
ī����һӦ��ȫ������һ����Ϸ̨��̨�����ڳ��š�����������
̨�²�ʱ�ش���Ʊ���ǵĽ�Ծ���Ȳ�������Ҳ�̲�ס��������
����Ϸ������һ�½�ǡ�
LONG);
//	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/piaoyou": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"beidajie1",
		"north"     : __DIR__"majiu",
	]));
	setup();
	replace_program(ROOM);
}
