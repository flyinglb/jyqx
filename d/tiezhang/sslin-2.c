// Room: /u/zqb/tiezhang/sslin-2.c

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
  "north" : __DIR__"sslin-3",
  "south" : __FILE__,
  "west" : __DIR__"sslin-1",
  "east" : __FILE__,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

