
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺȺ��
Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ�
��(chuan)���������ż����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ�
��������Ǿ��Ǳ����ˣ�������һ���޼ʵĴ󺣡�
LONG );
	set("exits", ([
                "west" : __DIR__"road10",
	]));
	set("item_desc", ([
                "chuan" : "һ�Ҵ󷫴�����úܽ�ʵ���������Գ�Զ���ġ�\n",
	]));
	set("objects", ([
                __DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" :1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

