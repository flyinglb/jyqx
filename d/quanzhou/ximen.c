// Room: /d/quanzhou/ximen.c
// Date: May 12,1998 Java

inherit ROOM;

void create()
{
	set("short", "Ȫ������");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵ����š���������һ�����š�
LONG );
	set("exits", ([
                "east" : __DIR__"zhongxin",
                "west" : __DIR__"westbridge",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

