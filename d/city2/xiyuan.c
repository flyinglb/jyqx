
inherit ROOM;

void create()
{
	set("short", "����ϷԺ");
	set("long", @LONG
������������ĳ���ϷԺ������Ϸ����̨��(stage)��Ϸ��
̨�º�ѹѹ��һƬ�����ˡ�������������ǽ���ס�����Ȳɡ�
�����Ǻ�̨��
LONG );
	set("exits", ([
		"south" : __DIR__"xichang1",
                "up" : __DIR__"stage",
                "east" : __DIR__"houtai",
	]));
        set("item_desc", ([
		"stage" : "\n����Ϸ̨����ͻȻ�������̨���ݵĳ嶯��\n" ,
	]));
        set("objects", ([
		"/d/city2/npc/guanzho":  5,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object man,*ob;
    if(dir=="up")
    {
 	if(!me->query_temp("hastryup"))
        {
        me->set_temp("hastryup",1);
       	if((int)me->query("meili")>=20)
		{
	message_vision(  
	"ֻ��������һƬ������������һ����ơ����˴���˵����\n"
	"��һ�����뿴��λ" + RANK_D->query_respect(me)+ "���ݡ�\n",this_player());
        return ::valid_leave(me, dir);
	        }
        	else
		{
	message_vision(
	"\nͻȻ����һӵ���ϣ���$N��е���ƾ��Ҳ����̨���£�������������" +
                        RANK_D->query_rude(me) + "��\n",this_player());
        if(!present("jia", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho1");
	man->move(this_object());
	}
	if(!present("yi", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho2");
	man->move(this_object());
	}
	if(!present("bing", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho3");
	man->move(this_object());
	}
	if(!present("ding", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho4");
	man->move(this_object());
	}
	if(!present("wu", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho5");
	man->move(this_object());
	}
	ob = all_inventory(this_object());
	for(i=0; i<sizeof(ob); i++) {
		if( !userp(ob[i]) ) { 
			ob[i]->set_leader(me);
			ob[i]->kill_ob(me);
			me->fight_ob(ob[i]);
		}
		}
        return notify_fail("������ƴ��Ҳ��������̨��\n");
        }
}
message_vision("$Nƴ������̨ȥ��\n",this_player());
return ::valid_leave(me, dir);
} 
return ::valid_leave(me, dir);
}
