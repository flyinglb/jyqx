// Room: /d/shaolin/bagua.c
// Date: YZC 96/01/19
// Date: CLEANSWORD 96/05/19

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
������Ǻ�Ĺ�������ġ�վ��������ܿ��������
�����Σ�ֻ����Χĺ�����������������������߼ʡ�һ����
�����籼�߰㴩����䣬�����������ס�����ż���������
�޽��������׵��ŵص������������һ����������˵����
�Ĺ���ɾ塣�������д���һ����̶(tan)����֮����ס�
LONG );
	set("item_desc", ([
		"tan":  "��̶�ߵ���ʯ�Ͽ����ĸ��޴�Ĺ�׭������ź�̶����\n"
			"�������С�֣��������ӽ��顱�� ̶�߶��Ǽ�Ӳ�������ң�\n"
			"̶ˮ�α�͸������Ϻ������ˮ����������һ�����ĵ�����ɫ��\n"
			"�߽����һ�ɳ��Ǻ������������  �ֿ��ƺ�ֻ�м�ʮ���\n"
			"��ϸ����ȥȴ��Խ��Խ�ֱ���޵���Ԩһ�㣡\n",
	]));
	set("exits", ([
		"up" : __DIR__"andao3",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="tan" ) 
	{
                if( present("pishui zhu", me) ) 
		{
			message_vision("$Nȡ����ˮ���飬�����������һ�ݣ�Ծ�뺮̶֮�С�\n", me);
	                me->move("/d/shaolin/hantan1");
        	        message("vision", "ֻ��ˮ�滩��һ���죬�ƺ�����ҲǱ��ˮ����\n",
                		environment(me), ({me}) );
		}
		else
		{
			tell_object(me, "��һ����ˮ�У�ֻ��ʴ�Ǻ�����ȫ��������ë�����룬��֫������ȫ��ľ��\n"
					"�����ŵ����в����һ����������ס̶�ߵ���ʯ������ææ�����˳�����\n");
        	        message("vision", me->name() + "�°���һ����ˮ�У����̴��һ�����������Ƶ����˳�������\n",
                		environment(me), ({me}) );
		}

		return 1;
	}
}

