
inherit ROOM;

void create()
{
	set("short", "ȫ�۵¾�¥");
	set("long", @LONG
��Բ������������ȫ�۵¾�¥����˵�����˲�֪�����˲�����¥
�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ
�ˡ�¥����������
LONG );
	set("exits", ([
		"east" : __DIR__"wangfu2",
		"up"   : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

