//Room: /d/dali/biluoshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ��");
	set("long",@LONG
�˼���������ɽ���£�����������ɽ�¶��ϣ����ؿ���һ��Ҳ��
���֣������ϡ�衣���ĵ���ũҵ������л����ָ��������ڲ�ͬ
�ļ��ڸ�����ͬ����أ���฽�������������������˸�����
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"yixibu",
	]));
	setup();
	replace_program(ROOM);
}

