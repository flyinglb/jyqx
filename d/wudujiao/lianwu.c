// by mayue


inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������Ժ�ڵ����䳡�����������ϰڷ���һЩ������ʯ����ɳ����
һ��СͷĿ����ָ���������䡣 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"dating",
		"south" : __DIR__"nanyuan",
		"west" : __DIR__"damen",
		"north" : __DIR__"beiyuan",
	]));
        set("objects", ([
                  __DIR__"npc/jiaotou": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

