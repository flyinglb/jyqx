// Room: eastroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档����һ����ֱ�Ĵ�
�������߿���ͨ�������ţ����ϱ�ͨ���ϴ�֣����Ϸ�������������
��¥�ˡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "southeast"  : __DIR__"wangjianglou",
	    "southwest"  : __DIR__"southroad1",
	    "north"      : __DIR__"eastroad2",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
