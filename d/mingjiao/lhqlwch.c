// lhqlwch.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�߽����һ�������䳡����������Ľ����ǲ��������໥
�д��书�����Ǵ��������Ƶķ��𻤾ߣ���ѧϰʹ�û�ߺ���
׼������������ڵ�ԭ�ͣ�����ȼ�������ޱȡ�
LONG );
        set("exits", ([
                "east" : __DIR__"lhqyuan",
        ]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 5,
	]));                                                    
        set("outdoors", "mingjiao");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
