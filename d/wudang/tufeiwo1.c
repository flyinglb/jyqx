// tufeiwo1.c ����С·
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ��Ƨ��������С·�ϣ���������ɭɭ�����֡�ֻ������ǰ�󣬵���
��������ǵص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ���˵���ﾭ�������˳�û�����ɾ���������
�и�Сɽ��(dong)��
LONG );
        set("outdoors", "wudang");
	set("no_sleep_room",1);
	set("exits", ([
		"south"     : __DIR__"tufeiwo2",
		"northdown" : __DIR__"wdroad10",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 2
        ]));
//        set("no_clean_up", 0);
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
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underwd");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}
