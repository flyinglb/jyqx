// Room: /d/xiangyang/guangchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����㳡");
	set("long", @LONG
����������������㳡��������ʯ���档����ͨ�������ţ�
����ͨ��׻��ţ�����ֱ����ȸ�ţ�ԶԶ����ɿ�����������
������ʹ���š��������ɹŴ���Ŵι����������ٸ�Ϊ��ֹ��
�ż�ϸ���ӽ������Ѿ������������ڴ˾ۼ���ֻ��һ�ӹٱ���
������Ѳ�ߣ��㻹�ǿ��뿪�ɡ�
LONG );
        set("outdoors", "xiangyang");
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"west"  : __DIR__"westjie1",
		"south" : __DIR__"southjie1",
		"north" : __DIR__"anfupailou",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/bing" : 1,
	]));
	setup();
	replace_program(ROOM);
}

