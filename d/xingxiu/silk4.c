// /d/xingxiu/silk4.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
          set("long", @LONG
����һ����ԭ������֮����̵���������һ���޼ʵĴ�ɳĮ��
��˵���ﳣ�е��˳�û��������ͨ��һƬ�����ɽ�����������ͨ
����ԭ��·��·����һ��ʯ��(shibei)��
LONG );
        set("outdoors", "xingxiuhai");
        set("exits", ([
                "east" : __DIR__"silk3",
		"west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
		"southwest" : "/d/xueshan/caoyuan" ,
        ]));
        set("item_desc", ([
                "shibei" : "�������򣬶�����ԭ��˭�����У���ɱ���ۡ�����ɽ��������\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_push", "push");
        add_action("do_push", "tui");
}

int valid_leave(object me, string dir)
{
    if ((dir == "west")&& !userp(me)) return 0;
    return ::valid_leave(me, dir);
}

int do_push(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="shibei" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message_vision("$N�ƿ�ʯ����ֻ����ɳ�׷׵��䣬������¶��һ��С����\n", me);
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underxx");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	
