// Room: guangchang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ᶽ����");
	set("long", @LONG
������ᶽ���š�Ρ����ΰ�ĳ�ǽ�ϣ� "�ɶ��ᶽ��" �������
ʮ�����ۣ����ƻԻ͡������ױ��������ԡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south" : __DIR__"guangchang",
	    "north" : __DIR__"tidufu",
	]));
	set("objects", ([
	    __DIR__"npc/qinbing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir=="north") && (objectp(present("qin bing", environment(me)))))
		return notify_fail("�ױ���ǰ��ס�㣬����˵������λ" 
			+ RANK_D->query_respect(me) + "��ذɡ���ү�����͡�\n");
	return ::valid_leave(me, dir);
}

