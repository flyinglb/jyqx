// Room: /d/xingxiu/xxh1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
����ʯ����һ���ѷ�ͨ��һ��ɽ����������һ���ݾ���ͨ������ɽ��
LONG );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
             "south" : "/d/baituo/houmen" ,
             "westup" : __DIR__"tianroad3",
        ]));
        set("objects", ([
                CLASS_D("xingxiu")+"/zhaixing" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir != "north" && dir != "westup")
       { return ::valid_leave(me, dir); }
       else
       {
             if (objectp(present("zhaixing zi", environment(me))) && 
                 living(present("zhaixing zi", environment(me))))
             {
	           if ((me->query("shen") > 100))
                       return notify_fail(
"ժ���Ӻȵ�����λ" + RANK_D->query_respect(me) + "���ߣ�\n");
             }
             return ::valid_leave(me, dir);
      }
}
