// Room: /d/shaolin/yaopinku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ҩƷ��");
	set("long", @LONG
������ȫ��ɮ������ҩƷ�ĵط��������������Ź�ŨŨ
��ҩζ����ǽ��һ���Ÿ߼�������ҩ��ÿ��ҩ�����ϰ�
��װҩ��С���룬������������������ĸ��ֲ�ͷҩ������
��ǽ�߷��Ÿ��޴�İ���ɫɼľҩ���������Ÿ����з���
ӡǩ�Ĵ������һλ����ɮ��������æµ�ų���ҩƷ����ҩ
������
LONG );
	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

