// Room: /city2/aobai1.c


inherit ROOM;

void create()
{
	set("short","�ֵ�");
	set("long", @LONG
�������������ݸ��ˣ�˭Ҳ�������Ƕ�ȥ����������������֡�
·���и�����(dong)����ֻ������������̽ͷ��
LONG );
	set("exits", ([
		"west" : __DIR__"aobai2",
		"east" : __DIR__"wangfu1",
	]));
	set("item_desc", ([
            "dong" : "�ں����Ĺ�������֪���ж��\n",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
           {
               message("vision",
                        me->name() + "����ؤ�����ǹ���һ���������������˽�ȥ��",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underbj");
               message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
       }
}
