//Room: /d/dali/road3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ٵ�");
	set("long",@LONG
������һ����ʯ�ٵ��ϣ������Ѿ�����گ�����ˣ�·��ʱʱ����
������ɫ�����������������������䲻����·��վ��Щ�����λ��޵�
����Ů�ӣ�����һ�������µ��Եø�����������ȥ���ϼ��Ǵ����
���ؿ�̫�ͳǣ��عٵ��򶫱��ɴ���ԭ��
LONG);
	set("objects", ([
	   __DIR__"npc/girl": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"road2",
	    "south"      : __DIR__"dehuabei",
	    "northwest"  : "/d/wanjiegu/riverside2",
	]));
	setup();
	replace_program(ROOM);
}

