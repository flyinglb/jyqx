// by mayue


inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����Ǹ���԰��һ���ļ��������Ÿ�������Ļ��ݣ��������·����߲�
���޵Ĺ�ԡ���԰��һƬ���ţ���������һֻ�۷��������衣��һ��ʯ��
С·ͨ��ǰ��һ��������
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"huating1",
		"south" : __DIR__"huayuan2",
		"west" : __DIR__"dating",
		"north" : __DIR__"huayuan3",
	]));
        set("objects", ([
                 __DIR__"npc/tongzi": 4,
	]));
    

	setup();
	replace_program(ROOM);
}

