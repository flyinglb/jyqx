//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ٵ�");
	set("long",@LONG
����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ����˴�
�����ϣ�������ȥ����ɽ·ͨ���ƹ�ɽ�����̶��ɴ����Ѵ��������
ȥ�򱱲�Զ������������--����ɽ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/emei/qsjie2",
	    "southwest"  : __DIR__"road2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

