//Room: /d/dali/baiyiminju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
�����Ǵ����һ���壬���ɢ���ڲ�ɽ���������������������
ʯ���ݳɣ���ַ�񡣳��������죬�Ҽһ����������Ի�ľ�����ſڣ�
�ڴ��һ�����ġ���ɽ����������Ұ���������ۻ��֡�
LONG);
	set("objects", ([
	   __DIR__"npc/oldman": 1,
	   __DIR__"npc/girl1": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dahejieeast",
	]));
	setup();
	replace_program(ROOM);
}

