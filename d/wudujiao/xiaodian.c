// by mayue

inherit ROOM;

void create()
{
	set("short", "·��С��");
	set("long", @LONG
����һ��ɽҰС�꣬��ӦһЩʳ���ʱ��ɽ������������ϡ
�٣����һ��Ҳû������·������ϰ���ѵ꿪�����������
Ҫ���ˡ����ڽ���һ��ͷ����������˿��Խ�ȥ��Ϣ��
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"shanlu1",
//		"south" : __DIR__"milin1",
//                "west" : __DIR__"neijin",
//		"north" : __DIR__"road3",
	]));
        set("objects", ([
                __DIR__"npc/sun": 1,
	]));
   

	setup();
	replace_program(ROOM);
}

