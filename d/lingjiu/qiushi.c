//ROOM qiushi.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long",@LONG
���ǡ����չ�����Ѻ���˵ĵط������й��߻谵����ζ���š��ݽ���
��ԼԼ�и���Ӱ��
LONG );
        set("exits", ([
		"east" : __DIR__"men1",
        ]));
	set("objects",([
		__DIR__"npc/wulaoda" : 1,
	]));
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
