//Room: /d/dali/dalangan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����в�");
	set("long",@LONG
����������в�����Ĵ󣬿����������е��㰸��ɫ���㣬��
�ŵ�������ƾ�ϸ���Ե����ڲ�ͬ�����̵Ĺ�Ʒ��Ʈ����ζ�����䵱
�е�һ����ͷ�ر����ۡ����������Ǳ���ļ�������
LONG);
	set("objects", ([
	   __DIR__"npc/jisi1": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"dalangan1",
	]));
	setup();
	replace_program(ROOM);
}

