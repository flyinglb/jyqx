//Room: /d/dali/taiheju2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�;Ӷ�¥");
	set("long",@LONG
������̫�;ӵĶ�¥��¥�ݱ�������Щ�ֳ��ư壬���ٵĸ�
Ů����������������߳Ժ����֣�Ҳ������ī���ڴ�������̸��
�����洰�����������Կ��������廪¥ǰ��һ����ˮ��
LONG);
	set("objects", ([
	   __DIR__"npc/genu": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"taiheju",
	]));
	setup();
	replace_program(ROOM);
}

