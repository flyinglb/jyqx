//Room: /d/dali/hualang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����Ǵ�����ʹ��Ļ��ȣ������µ������滨��ݣ���������
�����������԰�����������ŷ���������ƫ�
LONG);
	set("objects", ([
	   __DIR__"npc/gongnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"yuhuayuan",
	    "north"  : __DIR__"zhengdian",
	    "east"   : __DIR__"piandian",
	    "west"   : __DIR__"yushanfang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


