// qianchi.c

inherit ROOM;

void create()
{
        set("short", "ǧ�ߴ�");
	set("long", @LONG
ǰ����һб���촹ʯ�ݵ�ɽ�ף�����Ǻպ�������ǧ�ߴ���ǧ�ߴ���
��һ�����Ҽ����ѷ쿪����ɣ�б��Լ��ʮ�ȣ���Լ��ʮ�ף�����һ����
�䡣̧ͷ����һ����⣬�����ұڶ��ͣ���ͷ�Ǹ���������ķ���ʯ����
�׳ơ��쾮�����쾮�Ե�Σ���Ͽ��С�̫���ʺ�����̡�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"huixinshi",
            "southup" : __DIR__"baichi",
        ]));
        set("objects", ([
            __DIR__"npc/youke": 2,
        ]));

//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
int valid_leave(object me, string dir)
{
        if (dir == "southup") {
		me->add("jing", -30);
		me->add("qi", -30);
	}
	return 1;
}	
