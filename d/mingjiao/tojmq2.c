//TORJQ2.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ƽ̹�����ƿ������������������ﻨ�㣬һƬ��ƽ��
������ա���ʱ����˭���뵽��������������¹����ٽ������˵�
Ѫ����Ƭ���������ж��ٲ���������������ԩ��Ĺǡ�Զ������Լ
�����������˵ķ�ľ����ż��������׷���𵶸������ɳ������
LONG );
	set("exits", ([
		"northwest" : __DIR__"tojmq3",
		"southeast" : __DIR__"tojmq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
