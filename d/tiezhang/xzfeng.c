// Room: /u/zqb/tiezhang/xzfeng.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", RED"Сָ��"NOR);
	set("long", @LONG
    ���ѵ�����Сָ��ķ嶥����ĿԶ��������Զ���ķ�����û��Ũ 
Ũ������֮�С�����ĸ߶�ǡ������֮�У���ֻ�ܿ�����ǰ���׵ľ����
���ģ�����·��ѱ�ˮ����ʪ������Ϯ����������ɪɪ������
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"pubu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

