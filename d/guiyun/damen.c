// Room: /guiyun/damen.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ��һ��ׯԺ����¥�����ߴ���ש���ߣ���ɫ�׵�����д
�š�����ׯ����������֡����ҽ�Ϊ�¾ɣ��߽Ǵ�����Ƥ�Ѱ��䣬
¶������ɫ��ľ�ʡ������������Ѳ��¶�ʮ�������ˡ�
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"enter" : __DIR__"qianyuan",
		"south" : __DIR__"matou",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�һ���") &&
		!me->query_temp("marks/guiyun") &&
		dir == "enter" &&
		objectp(present("jia ding", environment(me))))
		return notify_fail("�Ҷ����˸�Ҿ��˵����������ׯ����������ׯ��������ͣ�������ذɡ�\n");

	return ::valid_leave(me, dir);
}
