inherit ROOM;

void create()
{
	set("short", "��͵�");
	set("long", @LONG
��������͵������һ�����������ȣ�ͨ����Ժ���������м����Է���
�����ǹ���̫���ס����
LONG );
        set("outdoors", "huanggon");
	set("exits", ([
		"south" : "/d/city2/zhengmen",
		"west" : "/d/huanggon/zoulang1",
	]));
	set("objects", ([
		"/d/huanggon/npc/shiwei" :1,
		"/d/huanggon/npc/taijian" :1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
me->delete("huanggong\\canenter");
return ::valid_leave(me, dir);
}
