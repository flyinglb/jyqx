//dongnei.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
	     "������ɽ�������ѵ����ڡ��Ա���һ�ප��������������Ů�ӵĿ�����\n"
	);
	set("exits", ([
		"west" : __DIR__"cedong",
		"south" : __DIR__"dongkou",
	]));
	set("objects",([
		__DIR__"npc/shanzei3" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{

	if (  (dir == "west")
	   && objectp(present("shanzei tou", environment(me))) )
	 return notify_fail
		("ɽ��ͷ����ȭͷ������ռ�����ŵı��ˣ������\n");
	return ::valid_leave(me, dir);
}
