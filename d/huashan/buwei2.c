// buwei2.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
����������Ⱥ�����ң�����Ⱥ�ڽ������˳ơ����ӽ���������Ϊһ��
�����ţ�����������ȴ���õĺܼ򵥡�����һ�Ŵ�����ֻ���ӣ�ǽ������
��ױ̨��ֻ�п�ǽһ�ź�ľ����(desk)���Ե��������ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"buwei1",
        ]));
	set ("item_desc", ([
		"desk" : 
"����һ�źܽ�ʵ�ĺ�ľ�����������ϰ��ż�ֻ�Ǻ��ʣ�ĥ��һ���ī��\n"
"����һ��δ�õİ�ֽ��\n"
	])  ) ;

        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
	object paper;

        if( !arg || arg=="" ) return 0;

        if( arg=="desk" )
	{
		if (!query("hs_trigger"))
		{
			message_vision(
"$N��������������������ص������ƺ�����û��...��ͻȻ��������\n"
"ǽ��֮��Ʈ���һ��ֽ��\n", this_player());
			paper = new(__DIR__"obj/paper");
			paper->move(__FILE__);
			set("hs_trigger", 1);
			return 1;
		}
		message_vision(
"$N��������������������ص�������˿������\n", this_player());
		return 1;
	}
	return 0;
}
