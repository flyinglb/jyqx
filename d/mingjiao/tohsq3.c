//TOHSQ3.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ӽ��ȵ��ˣ��������ٲ���ס��ȥ·���ٲ���һƥ����
�������£���к��һ��̶֮�У�ˮ������������ֱ������������ɽ
ʯ���ʣ����ڶ��£������˹����Ͷ��ɡ���̶ǰ����ʯ��ĥ�������
����������������������
LONG );
	set("exits", ([
		"southeast" :__DIR__"tohsq2",
//		"northwest" :__DIR__"tohsq3",
	]));

	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        me=this_player();
        if(!arg)
        {
message_vision("$Nһ���ۣ���̶��������ȥ��ֻ������̹ǣ��Ͻ������࿹��\n",me);
                me->move("/d/mingjiao/hsqtan1");
                return notify_fail("\n");
        }
}


	

