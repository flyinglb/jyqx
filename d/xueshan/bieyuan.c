//      bieyuan.c ѩɽ��Ժ
//      Designed by secret (����)
//      97/05/25

inherit ROOM;

void create()
{
        set("short","ѩɽ��Ժ");
        set("long",@LONG
������ѩɽ�µķֲ������깱�Ʋִ����ﲻԶ�����
����ʥ������Ϊ��ʦ�����ڴ˴�����𷨡�
LONG );
        set("exits",([
                "east" : "/d/city2/road5",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 2 ,
                CLASS_D("xueshan") + "/guoshi" : 1 ,
        ]));
//        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "east" ) return 0;

	return ::valid_leave(me, dir);
}
