// by mayue

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
һ�����ѵ�С·����ɽ����ǰ���죬������Ũ�ܵ����֣���
������᫲�ƽ��ɽ·��ǰ����ǿ��µĺ�ɭ���ˡ��Ա��ƺ���һ
��ɽҰС�꣬·����һ��ʯ��(bei)��
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"southeast" : __DIR__"xiaolu",
		"south" : __DIR__"milin1",
		"west" : __DIR__"xiaodian",
		"north" : __DIR__"road3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
   
   set("item_desc",([
    "bei":"           ǰ����ɭ��ɽ�����ܣ�����֮�ڲ������̣�\n
           �л��ǳ�û���У���������˼�����У�\n",
]));

	setup();
	replace_program(ROOM);
}

