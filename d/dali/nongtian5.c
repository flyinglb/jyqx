//Room: /d/dali/nongtian5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
	set("long",@LONG
����һС����ͨ��ˮ�������Ϫ�����������ʮ�ַ��㡣Χ��
ũ�����һƬƬɣ�֣������˲�ɣ�����ϣ���֯�൱���µ�˿֯Ʒ��
����������ӡ�
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu2": 1,
	   __DIR__"npc/cow": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"buxiongbu",
	    "east"   : __DIR__"langan3",
	]));
	setup();
	replace_program(ROOM);
}

