//Room: /d/dali/heilongling.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
���������к�÷���꣬���Ѱ�ʴ�ݾ��������Ƥ�����ʰ�쵣���
���ڵأ��������죬�罾�������壬���������������Ƭ�����
���巼Ϯ�ˣ���ֲ֪�Ժδ����ഫ��Ϊ��÷���ɻ�ȻҲ���������
����̶��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xiaodao1",
	    "south"      : __DIR__"shulinwai",
	    "southwest"  : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

