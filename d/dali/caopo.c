//Room: /d/dali/wumeng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
һ��Ƭɽ�³�����ݣ����Ƿ���ţ��ĺõط�������������ߣ�
��ճ�����ɫ������ɽ����ľ�Ѿ����٣������϶��ǵͰ���ľ��ݵء�
���ٸ����Ĵ����ڴ˷�����
LONG);
	set("objects",([
	    __DIR__"npc/muyangren": 1,
	    __DIR__"npc/muyangnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"wumeng",
	]));
	setup();
	replace_program(ROOM);
}

