//Room: /d/dali/zoulang4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ��������˵����ҡ����˶�¥��ë
ձ�Ѿ����ɴ��ף�����ľ���ϻ���л�����棬�����Щ��ʱ��
���ֻ���ÿ���߰˲�������һ����̨���������̴�ͭ�������γ���
��֮����һ��
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "enter"    : __DIR__"guibingshi2",
	    "west"     : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

