// Room: /d/fuzhou/rongcheng2.c
// Date: Feb.14.1998 by Java
inherit ROOM;

void create()
{
	set("short", "�ų����¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����
Сľ�������ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ�����
�㿴���������Ŵ��ǿյģ���������ŵ����˹�ȥ��
LONG );
	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
	    "down" : __DIR__"rongcheng",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
