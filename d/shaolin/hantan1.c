// Room: /d/shaolin/hantan1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ź�̶");
	set("long", @LONG
���Ǻ�̶֮�С�����ˮ���������ƺ���һ�ɰ����ڼ���ǣ��
�������³���͸��̶ˮ��Լ�ɼ�̶�ܵ��ұڣ���������ˮ���弤
ĥ����ʮ�ֹ⻬����Ȼ���к��˱�ˮ�飬����ȴ��Ȼ�о���˿˿
�������뼡��������Խ�����£�ˮ�׵�����Խǿ�����������
LONG );
	set("no_clean_up", 0);
	setup();
}

void init()
{
	call_out("down", 10, this_player());
}

void down(object me)
{
	tell_object(me, "ֻ���ŵ�ˮ��������һ��ǿ�����������������ȥ...\n");
	me->move(__DIR__"hantan2");
}

