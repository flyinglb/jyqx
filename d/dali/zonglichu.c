//Room: /d/dali/zonglichu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
��������������̫���������֮������������������þ�����
�������ܰ��˺ܶ�軨�����涷�ޡ��軨�Ǵ���������������˶���
Ҳ���Ӱ��мӡ�
LONG);
	set("objects", ([
	    __DIR__"obj/shanchahua": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"sikong",
	    "south"  : __DIR__"wfdating",
	    "east"   : __DIR__"sima",
	    "west"   : __DIR__"situ",
	]));
	setup();
	replace_program(ROOM);
}

