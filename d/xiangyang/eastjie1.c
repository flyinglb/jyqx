// Room: /d/xiangyang/eastjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ
����ʮ�ֽֿڡ�����������������㳡�������������سǴ�
����ĸ�ۡ���ţ�ֻ���Ƕ��ر�ɭ�ϣ������˵�һ���ǲ��ܽ�
���ġ�����Ʈ��һ���Ƶ�ҩ�㣬�ޣ�ԭ����һ��ҩ�̡�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"eastjie2",
		"west"  : __DIR__"guangchang",
		"south" : __DIR__"yaopu",
		"north" : __DIR__"jiangjungate",
	]));
	setup();
	replace_program(ROOM);
}

