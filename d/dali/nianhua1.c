//Room: /d/dali/nianhua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�黨�º�Ժ");
	set("long",@LONG
��ٲ����£�ֻ���ö����������࣬���ƴӺ�Ժ��������ʱ֮�䣬
ֻ�б����������⾲���С���̤ʵ����Ժ����Ҷ���߽���Ժ����վ��
ͥ�У��ۼ�ͥ��һ�깫������һƬ��Ҷ�������䣬����ȫ����
LONG);
	set("objects", ([
//	   __DIR__"npc/huangmei": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "out"  : __DIR__"nianhuasi",
	]));
	setup();
	replace_program(ROOM);
}

