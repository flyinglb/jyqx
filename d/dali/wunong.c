//Room: /d/dali/wunong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ū��");
	set("long",@LONG
�˴��ѵ�����ı����������ɵ�����θ������������ģ�����
����ڸ�ɽ�ϡ�����������ɽ֮�������ٲ�����ӿ�Ĵ�ɺӡ���İ��
��ɽʯ�ݳɣ������࣬����ȫ�ǡ��˳ǲ�������ɽ�Ϸֲ���Щ����
��ӣ������˸���ţ���������
LONG);
	set("objects", ([
	   __DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : __DIR__"daduhe",
	    "southdown"  : __DIR__"shanlu1",
	    "east"       : __DIR__"wumeng",
	]));
	setup();
	replace_program(ROOM);
}

