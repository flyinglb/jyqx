
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������Ƕ������ţ����Կ������������̫�ࡣ�����Ʒ��Ĺٱ�
���ڲ�������ʱ�ش����ź���������㲻�������Ļ�����û��ǸϿ�
�뿪��
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin1",
		"north" : __DIR__"di_an1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

