//Room: /d/dali/hole.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��С֥�ƶ�");
	set("long",@LONG
���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ��
�飬ʯ��ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ
�ƽ�ˮ�������ֺ���ʯ��δ䣬���Ŀɰ���
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"changhu",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

