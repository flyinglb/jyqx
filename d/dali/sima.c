//Room: /d/dali/sima.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","˾����");
	set("long",@LONG
�����Ǵ����˾���á�������ǿ�Σ�������ެ���������߽���
������˾���Ͷ�֮��������ެ���Ѵ����Ѿã�ÿÿǿ��в�ȣ�����
�ò��ر���������
LONG);
	set("objects", ([
	    CLASS_D("dali")+"/fanye" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"zonglichu",
	]));
	setup();
	replace_program(ROOM);
}

