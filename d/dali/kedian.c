//Room: /d/dali/kedian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�͵�");
	set("long",@LONG
����ϲ�ݳ���Ψһ��һ�ҿ�ջ��ר�ŽӴ��������̣�����ǳ���
¡����С����������æ������ת���˼���ƫԶ��ȴ�����ƿ��׿��ˣ�
ס��һ��ֻҪ�������ӡ�
LONG);
	set("objects", ([
	   __DIR__"npc/puren": 1,
	]));
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("exits",([ /* sizeof() == 1 */
	    "west"    : __DIR__"xizhou",
	    "up"      : __DIR__"kedian2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
