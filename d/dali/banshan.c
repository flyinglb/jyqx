//Room: /d/dali/banshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ����");
	set("long",@LONG
һ��Ƭï�ܵĳ������������ڰ�ɽ���Ļ����ϡ����ӶԴ������
��������˵�ǣ�������Ҫ�Ľ������ϣ�Ҳ���ճ�������Ʒ��ԭ���ϡ�
ɽ�µĴ�ׯ��İ����˾�����ɽ���ɷ����ӡ�����ɽ����Ϫ���£���
����ˮ���Ѿ��Ĵ�ɽ�񾭳��ѿ����µ����Ӷ���Ϫ�У�����˳ˮƮ
���������Ӹ�����Ϫˮ������������
LONG);
	set("objects", ([
	   __DIR__"npc/kanzhuren": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : __DIR__"shanjian",
	    "east"     : __DIR__"buxiongbu",
	]));
	setup();
	replace_program(ROOM);
}

