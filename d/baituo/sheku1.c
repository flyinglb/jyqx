// muwu1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ǰ���ɽ�������ߵ�ƫ����һ�������ʯ�ݣ���ǽ�Ĺ�����
���Ŵ��СС���Ǹ����ӣ�һ����Ŀ�ɲ�������һ�Բ�����ע�����㣡
LONG );
	set("exits", ([
                "west" : __DIR__"dating",
                "east" : __DIR__"sheku",
	]));
 	set("objects", ([
        __DIR__"npc/laogu" : 1,
	]));
        set("no_fight", "1");
        replace_program(ROOM);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && me->query("family/family_name") != "����ɽ��" )
        return notify_fail("����ֻ�а���ɽ���Ӳſ��Խ�����\n");
        return ::valid_leave(me, dir);
}
