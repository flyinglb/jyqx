//Room: /d/dali/road5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����·");
	set("long",@LONG
�����Ǵ����ڣ�������һ��������·�ϣ����˶��Ǳ��صİ�
�����ˡ�Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ�����
������·ͨ������ǵ����ţ����пɴ�㶫��ɽ��
LONG);
	set("objects", ([
	   __DIR__"npc/yetu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"shuangheqiao",
	    "southeast"  : "/d/foshan/road1",
	]));
	setup();
	replace_program(ROOM);
}

