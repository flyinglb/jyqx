// Room: /lingzhou/malan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������Ӫ����������һɫ���ɹŸ�ͷս�����ľ��ж�����
���������о���ս��ȥ��磬�������磬��������ı뺷�����ɵ���
�������в��硣����Ӫ��ս����Ǿ�ѡ�������׳��������������
����ڶ��Ͳ��ϣ�һ�����ζ�Ͳ��ϵĻ��ζ��Ʈ�˹�����
LONG );
	set("exits", ([
		"east" : __DIR__"biaoqiyin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

