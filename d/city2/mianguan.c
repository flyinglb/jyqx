// Room: /city2/mianguan.c


inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�Ҽ�Ǯ��������ݣ�����ǳ���¡������οͶ�ѡ��������ţ���
������������������صķ������顣������Ҳ��ϲ���������С����������
æ������ת���Ӵ�����ǻ�����Ŀ��ˡ������������Сľ���ԣ������˸��ָ�
����ʳ�͡�
LONG );
        set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
                "/d/huashan/npc/haoke" :2,
	]));
	set("exits", ([
		"west" : __DIR__"alley1",
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir == "west")&& present("mian", this_player())
	&& objectp(present("xiao er", environment(me)))&&living(present("xiao", environment(me))))
	 return notify_fail("С����Ц�����Բ����治�ܴ�����ݡ�\n");
return ::valid_leave(me,dir);
}
