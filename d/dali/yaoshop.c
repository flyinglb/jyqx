//Room: /d/dali/yaopu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@LONG
����һ�����ص�ҩ�̣������ڴ�ͽֺ������ĵĽ��紦����ͨ��
��������ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���ҩ���ϵļ��ٸ�
С������ɢ��������һ��ŨŨ��ҩζ�����㼸����Ϣ����˵��ҵ���
��һ�ֺ����ܵ�ҩ�
LONG);
	set("objects", ([
	   __DIR__"npc/hehongyao": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"taiheeast",
	]));
	setup();
	replace_program(ROOM);
}

