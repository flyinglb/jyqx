//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
������Ǵ���Ļʹ�ǰ���֣����湬���ϵ��Ҷ�д�š�ʥ�ȹ���
�������֡��������۶������ѵ������³���Ϊɮ�ˣ�����ľ�����
�¾Ͷ����������������ˡ�
LONG);
	set("outdoors", "dali");
	set("objects",([
	    __DIR__"npc/weishi2": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"paifang",
	    "north" : __DIR__"gongmen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

