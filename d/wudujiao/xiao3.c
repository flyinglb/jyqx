// by mayue

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а�
���಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣
ǰ����һ��ľ��(pai)����·����,���ڷ紵��ɹ���ּ��Ѿ�ģ���ˡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"southeast" : __DIR__"xiaolu",
		"southeast" : __DIR__"taohua",
//		"west" : __DIR__"wumiao",
		"northwest" : __DIR__"xiao2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
   set("item_desc",([
    "pai":"         ǰ���һ���......,.....����.....Σ�ա�����֮��....���롣\n
                                                �峤  ������ \n",
]));
   

	setup();
	replace_program(ROOM);
}

