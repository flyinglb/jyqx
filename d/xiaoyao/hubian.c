// hubian.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ǹȵ׵Ĵ������ˮһƽ�뾵���¹�ӳ����У�����Ҳ��һ���
���Բ�¡����ϻ�����һ�ԴԵĸ�ʽ�����Ĳ軨�����¹���ҡҷ���ˡ��˺�
����Բ��״���󲿷������˻������С���������ȫ����ʯ(stone) �����£�
(xuanya) ��������ʮ�ֶ��ͣ���ʹ�Ǿ����ĸ��֣�Ҳ�޷���Ե���ϡ�
LONG );
	set ("item_desc", ([
		"stone" : "���涼����ʯ��������������������һ���е����ڲ�ͬ��\n"
	])  ) ;
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"gudi",
	]));
	set("no_clean_up", 0);
        set("outdoors", "xiaoyao" );
	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="stone") return 0;
	write("������˫�ۣ�˫�ַ���һ����ʯ�����һ������������\n");
       if(random((int)me->query("kar")) < 9 )
		{
                write("��ʯ�ζ���һ�£�����һ�μ��ء�\n");
		return 1;
		};
	write("��ʯ����ת����ֻת��һ�룬�����ʯ��¶��һ���������ߵĶ�Ѩ(hole)��\n");
	me->set_temp("marks/push",1);
	return 1;
}

int do_zuan(string arg)
{
	object me;
	me = this_player();
	if (!me->query_temp("marks/push")) return 0;
	if ( arg != "hole") return 0;
	message_vision("$N��ϲ֮�£�Ҳûȥ���Ƕ�������Σ�գ���һ���������ɽ���\n", me);
	me->move(__DIR__"yandong");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
	return ::valid_leave();
}
