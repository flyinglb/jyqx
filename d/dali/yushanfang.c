//Room: /d/dali/yushanfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ŷ�");
	set("long",@LONG
�����Ǵ�����ʹ������ŷ�������ĳ��߶��ǽ������ɵġ���
�۲�������Ҳ��Ϣ���ˣ������ǳ��ȡ�
LONG);
	set("objects", ([
	    __DIR__"npc/taijian": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"hualang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

