// Room: /d/shaolin/jianyu1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ���
���ɣ�ֻ���ϱ������һ��С�ţ����Ͽ��˸����ƴ�Ķ�������
�ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��
һ�߰׵÷����Ŀݹǡ�
LONG );
	set("exits", ([
		"north" : __DIR__"jianyu",
	]));
	set("objects",([
		"/d/shaolin/npc/yu-zu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

