// by mayue


inherit ROOM;

void create()
{
	set("short", "�");
	set("long", @LONG
����һ����ª������ıڶ����̻�Ѭ�ĺں����ģ���̨�Ե�ǽ��
����һ�ŷ��ƵĻ���ֽ���Ա߹���һЩ��ɵ����⡣��̨�����Ե�ˮ��
�ϰ��ż�ֻ�ִɴ��룬�ݵ�һ�Ƕ���һ�����ա� 
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"out" : __DIR__"cun7",
//		"south" : __DIR__"minju1",
		"east" : __DIR__"minju3",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                  __DIR__"obj/qhcwan": 2,
                  __DIR__"obj/shourou2": 1,
                  __DIR__"obj/shourou1": 1,
	]));
       set("resource", ([ /* sizeof() == 1 */
              "water" : 1,
       ]));   
    set("item_desc",([
    "����ֽ":"         ľ�˵���һ�Ρ�����\n",
]));
	setup();
	replace_program(ROOM);
}

