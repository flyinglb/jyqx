//Room: /d/dali/guibingshi1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
����һ�����ң����ﴰ���������þ߿��������Ǵ���һ��
����������Ǽ�ֵ���ơ�ƾ�������������ڵ���֮�пɼ���ɽ��
��ַ壬ֻ��ɽ�����㣬������Σ������Ŀ�������
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

