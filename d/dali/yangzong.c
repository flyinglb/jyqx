//Room: /d/dali/yangzong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
������ǿ�ڲ��Ĵ�����ôЩ����ľ۾�����ôЩ�����ǰ���
��һ֧���˴�Ҳ��ɽ���С��ƽԭ����������һƬ��ˮ������������
��ط���΢ƫԶЩ�������൱���ٵİ����������ڸ��������Ϸ��е�
·ͨ����������
LONG);
	set("objects", ([
	   __DIR__"npc/bshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westup"     : __DIR__"shanlu8",
	    "northeast"  : __DIR__"nongtian4",
	    "southup"    : __DIR__"sanglin",
	    "southwest"  : __DIR__"milin",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

