//Room: /d/dali/gudao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ŵ�");
	set("long",@LONG
һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ����������һ���޼ʵ���
˫���ɴ�ɭ�֡����������һƬ��ΰ������һ�������ĺ�ǽ������
Խ��ǽͷ�ɼ�һ����¥���������Ǵ�����ʤ�廪¥��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"   : __DIR__"dating",
	    "west"    : __DIR__"shanlu6",
	    "east"    : __DIR__"luyuxi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

