// Room: /d/xiangyang/eastjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣����������
���ţ��ϱ���ľ���̣���ľ������ľ���������������������
�ǵĶ���Ӫ���������������洫���α��Ĳ�������������һ��
ʮ�ֽֿڣ�ֻ���������������ﲻ����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"eastgate1",
		"west"  : __DIR__"eastjie2",
		"south" : __DIR__"mujiang",
		"north" : __DIR__"bingying2",
	]));
	setup();
	replace_program(ROOM);
}

