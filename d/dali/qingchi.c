//Room: /d/dali/qingchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
�������������ܵ��������е��徻����ؽ�����گ��䣬������
�����ڴ���԰�ֹ����İ����£������˲ʡ�������Ϻ��浹Ҳ���˲�
�٣������ļ��紺�������£��ɻ�˯���ޱ���次�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"sheguta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

