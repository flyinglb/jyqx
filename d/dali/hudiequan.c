//Room: /d/dali/hudiequan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����Ȫ");
	set("long",@LONG
����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷����㼯�������£�
�����У��������裬��ǧ����ֻ�ʵ�������һ����ʹ�����û��Ž��ء���
�����ں���Ȫ�ϣ�˳���ǵ���������������������һֻҧ��һֻ��β������
��ǧ�ٸ�����������������Ͷʯ��ɢ���������˾�̾����ۡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguanqian",
	    "east"   : __DIR__"xiaodao1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

