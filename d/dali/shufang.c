//Room: /d/dali/shufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�鷿");
	set("long", @LONG
���Ǵ�������������鷿����������һ����ľ�����Ϸ��Ų����飬
��ǽ�ĵط�����һ����ܣ����������������￴�顣
LONG);
	set("objects",([
	    CLASS_D("dali")+"/zhudanchen":1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"tingfang",
	]));
	setup();
	replace_program(ROOM);
}

