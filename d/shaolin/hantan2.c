// Room: /d/shaolin/hantan2.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ź�̶");
	set("long", @LONG
���Ǻ�̶֮�С��������ѿɸо�����ˮ�µľ޴�ѹ��������
������̶ˮ��������������һ�㱡���ı��ǣ���֫Ҳ�ѿ�ʼ��ľ��
����е�����Ͷ�㶼��Ϊ���ѡ�ˮ�е�����Ҳ������ǿ���㲻��
���������³�ȥ��
LONG );
	set("no_clean_up", 0);
	setup();
}

void init()
{
	call_out("down", 5, this_player());
}

void down(object me)
{
	tell_object(me, "ֻ���ŵ�ˮ��������һ��ǿ�����������������ȥ...\n");
	me->move(__DIR__"hantan3");
}

