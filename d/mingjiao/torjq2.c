//TORJQ2.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ƽ̹�����ƿ������������������ﻨ�㣬һƬ��ƽ��
������ա���ʱ����˭���뵽��������������¹����ٽ������˵�
Ѫ����Ƭ���������ж��ٲ���������������ԩ��Ĺǡ�Զ������Լ
�����������˵Ĵ�������ż��������׷���𵶸������ɳ������
LONG );
	set("exits", ([
		"northeast" : __DIR__"torjq3",
		"southwest" : __DIR__"torjq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
