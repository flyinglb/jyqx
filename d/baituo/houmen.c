//room: houmen.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
       "���Ǹ�ɽׯ�ĺ��š������нݾ�����ͨ�����޺���\n"
	);
	set("exits",([
		"north" : "/d/xingxiu/xxh1",
		"south" : __DIR__"tuyuan",
	]));
        set("objects", ([
            __DIR__"npc/menwei" : 1 ,
        ]));
//        set("no_clean_up", 0);
	set("outdoors", "baituo");
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "south")
	   && ((int)me->query("shen") > 300)
	   && objectp(present("men wei", environment(me)))) 
	 return notify_fail
		("��������һ���������������������һ���Ͷ��ģ������\n");
	return ::valid_leave(me, dir);
}
