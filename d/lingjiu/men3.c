//ROOM men3.c
inherit ROOM;
void create()
{
	set("short", "�չ��Ҵ���");
        set("long",
	     "���Ǳչ����ϱߣ�������һ�ȴ��š�\n"
        );
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"biguan",
		"south" : __DIR__"xiaodao2",
        ]));
    	set("objects",([
                __DIR__"npc/shisao" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north")
        && !wizardp(me)
           && ((string)me->query("family/family_name") != "���չ�")
	   && objectp(present("shi sao", environment(me))) )
	 return notify_fail
		("ʯɩ������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
	return ::valid_leave(me, dir);
}
