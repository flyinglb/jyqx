//Room: /d/foshan/street4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ���");
	set("long",@LONG
����ڷ�ɽ������һָ�Ĵ󻧣���ҵļҶ���ǣ���ǹ�������
�һ��İ���ֻ������͵����һ����ֺ�ب������·��һ������
������Ĵ��¥��������д�š�Ӣ��¥������������֣����߳���
��������¥�ﵶ����죬�����������������·���м��ձ������̣�
���洫����������������
LONG);
	set("objects", ([
	    __DIR__"npc/wolfdog": 2,
	    __DIR__"npc/zhongxiaoer": 1,
	    __DIR__"npc/zhongsisao": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"youtiaopu",
	    "south" : __DIR__"yingxionglou",
	    "west"  : __DIR__"street3",
	    "east"  : __DIR__"street5",
	]));
	setup();
	replace_program(ROOM);
}

