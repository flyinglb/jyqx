// Room: /u/zqb/tiezhang/hhyang-2.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", HIR"����"NOR);
	set("long", @LONG
    ֻ�����������������ܰ�������١����ȡ���𡢺콶������ 
����ʢ�����㻨��Ժǽ���ֹ��˼�ľ�����������������飬����ܰ��Ϯ�ˣ� 
�����԰��԰�����Ϸ��ż�����ź����ϡ����ˡ����ʹ��������϶���һ�� 
���ȣ������ǰ�����Ϣ�ĵط���
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hhyuan-1",
]));
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

