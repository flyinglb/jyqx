//Room: /d/foshan/road8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�򸣽�Ȫ�ݣ��ϱ�����С·��ֻͨ��η���
LONG);
	set("objects", ([
	   __DIR__"npc/zhang": 1,
	   __DIR__"npc/zhangkang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west" : __DIR__"eastgate",
	    "east" : __DIR__"road9",
            "south" : __DIR__"road10",
	]));
	setup();
	replace_program(ROOM);
}

