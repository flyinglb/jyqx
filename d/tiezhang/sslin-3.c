// Room: /u/zqb/tiezhang/sslin-3.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    ���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�����������
������ա�������������Ҽ������������ڵ����������У��γ�������ɫ
�Ĺ�����ɷ�Ǻÿ������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У���
������ȥ��·�ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sslin-4",
  "east" : __FILE__,
  "south" : __DIR__ "sslin-2",
  "north" : __FILE__,
]));
    set("objects",([
            __DIR__"npc/laohu"  :        1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

