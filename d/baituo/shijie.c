//shijie.c
inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@TEXT
��������ʯ���̳ɵ�ʯ���ϡ�������Ǵ�˵�����صİ���ɽ��ԶԶ
��ȥ��������ɳ�ѻ��γɵ�ɽ�����һֻ���յļ�����һ��ɽ��������
����ǰ��
TEXT );
	set("exits",([
		"east" : __DIR__"caoping",
		"northup" : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

