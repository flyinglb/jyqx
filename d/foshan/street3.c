//Room: /d/foshan/street3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ���");
	set("long",@LONG
��ɽ�Թ������ɡ����¡����ڲ��������Ĵ��򣬶˵��������
�������ܷ�����һ����ֺ�ب�������ϱ������ţ�ͨ���Ϻ�������
�����ſ�����ɴ���ԭ��
LONG);
	set("objects", ([
	    "/d/city/npc/liumangtou": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"northgate",
	    "south" : __DIR__"southgate",
	    "west"  : __DIR__"street2",
	    "east"  : __DIR__"street4",
	]));
	setup();
	replace_program(ROOM);
}

