// Room: /d/xiangyang/westjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����ǰ׻�
���ţ�������һ����ʮ�ֽֿڣ�ֻ���������������ﲻ������
���Ǵ�У���������������ǵ�����Ӫ���������������洫����
�α��Ĳ�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"westjie2",
		"west"  : __DIR__"westgate1",
		"south" : __DIR__"dajiaochang",
		"north" : __DIR__"bingying4",
	]));
	setup();
	replace_program(ROOM);
}

