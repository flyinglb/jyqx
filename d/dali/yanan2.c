//Room: /d/dali/yanan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�س�С·");
	set("long",@LONG
����һ�����ŵ���ϰ���С·������а������Ϯ�ˡ�Զ�����
���棬�̲�����������Ϸˮ��ңң�ɼ��δ����洬�ᷫ���ơ��˵���
�˼��ɾ�����·����ֱ�ϵ��������Ⱥɽ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"    : __DIR__"yanan1",
	    "westup"  : __DIR__"bijishan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

