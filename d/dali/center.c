//Room: /d/dali/center.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���Ĺ㳡");
	set("long",@LONG
�������������ǵ����ģ���ɫʯ���̳ɵĴ�����ķ����ӡ���
�������Σ�һȦΧ�Ķ���С�������ˣ��Ϳ����ֵġ�������������Ⱥ
��Ҳ�ٲ��˼����ܽ���֮�ˣ�һЩ����ԭ����δ�ŵ�������һЩ����
����֮���˷ܲ��ѡ�
LONG);
	set("objects", ([
	   __DIR__"npc/jianghuyiren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"taihejiekou",
	    "south"  : __DIR__"shizilukou",
	    "east"   : __DIR__"taiheju",
	]));
	setup();
	replace_program(ROOM);
}

