// Room: chufang.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����һ����ĳ�����������Ŵ�Բ������Χ����ż������Ρ�����
�����ż���ˮ�ɻ���������һ�±��ӣ������������㣡Ҳ��֪�����ǻ�
�㻹�Ƿ��㡣ƽʱ�һ����ĵ��Ӻ����˶��������ò͡�
LONG );
	set("exits",([
	    "east" :__DIR__"qianyuan",
	]));

	set("objects", ([
	    __DIR__"npc/yan" : 1,
	    __DIR__"npc/yapu" : 1,
	]) );
//	set("no_clean_up", 0);
	setup();
        replace_program(ROOM) ;
}
//void reset ()
//{
//	::reset();
//	this_player()->delete_temp("taohua/�跹") ;
//}

