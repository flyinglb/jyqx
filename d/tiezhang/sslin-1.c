// Room: /u/zqb/tiezhang/sslin-1.c

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
  "east" : __DIR__"sslin-2",
  "west" : __FILE__,
  "south" : __DIR__ "shanlu-7",
  "north" : __FILE__,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

