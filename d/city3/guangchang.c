// Room: guangchang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�񶼹㳡");
	set("long", @LONG
�����ǳɶ��ᶽ��ǰ�㳡���ÿտ��ĵط���ֻ��ϡϡ���伸��û
����ɵ����ˡ���������ᶽ���ˣ��ϱ����ᶽ�֡��㳡��Χ����һ
Ȧ���������������԰���ʯ�㳡����ɹ�ù���ð�̡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"  : __DIR__"shuduroad1",
	    "west"  : __DIR__"shuduroad2",
	    "south" : __DIR__"tiduroad",
	    "north" : __DIR__"tidugate",
	]));
//	set("no_clean_up", 0);
	set("objects", ([
	    "/d/city/npc/wujiang" : 2,
	]));
	setup();
	replace_program(ROOM);
}
